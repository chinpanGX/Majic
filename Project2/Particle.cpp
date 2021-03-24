/*-------------------------------------------------------------

	[Particle.h]
	Author : �o���đ�

	�p�[�e�B�N���̏���
	�G�~�b�^�[����ɐ�������

--------------------------------------------------------------*/
#include "Particle.h"
#include "Utility.h"
#include <atldef.h>
#include <algorithm>

/*
using Microsoft::WRL::ComPtr;
HRESULT CreateStructuedBuffer(UINT NumElements, ComPtr<ID3D11Buffer> ppBuffer, ComPtr<ID3D11ShaderResourceView> ppSRV, ComPtr<ID3D11UnorderedAccessView> ppUAV)
{
	// �f�o�C�X�̎擾
	auto dev = DirectXGraphics::GetInstance().GetDevice();

	HRESULT hr = S_OK;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.ByteWidth = NumElements; *sizeof(T);
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.BindFlags = D3D11_BIND_UNORDERED_ACCESS | D3D11_BIND_SHADER_RESOURCE;
	bd.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
	bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
	bd.StructureByteStride = sizeof(T);

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = pInitData;
	dev->CreateBuffer(&bd, (pInitData) ? &sd : nullptr, ppBuffer);

	// SRV�̐���
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_UNKNOWN;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFER;
	srvDesc.Buffer.ElementWidth = NumElements;
	dev->CreateShaderResourceView(*ppBuffer, &srvDesc, ppSRV);

	// UAV�̐���
	D3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc;
	ZeroMemory(&uavDesc, sizeof(uavDesc));
	uavDesc.Format = DXGI_FORMAT_UNKNOWN;
	uavDesc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;
	uavDesc.Buffer.NumElements = NumElements;
	dev->CreateUnorderedAccessView(*ppBuffer, &uavDesc, ppUAV);

	return hr;
}
*/
GPUParticle::GPUParticle() : m_ParticleHost(MaxParticleCount)
{
}

GPUParticle::~GPUParticle()
{
}

void GPUParticle::Init()
{
	auto dev = DirectXGraphics::GetInstance().GetDevice();

	auto hr = dev->CreateBuffer(&CD3D11_BUFFER_DESC(sizeof(BufferCommon), D3D11_BIND_CONSTANT_BUFFER), nullptr, m_pConstBufferCommon.GetAddressOf());
	ThrowIfFailed(hr, "Faild CreateBuffer m_pConstBufferCommon");

	auto& tmp = m_ParticleHost;
	ATLVERIFY(m_ParticleHost.size() == MaxParticleCount);
	std::for_each(tmp.begin(), tmp.end(), 
		[](VertexParticle& x)
		{
			x.Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			x.Velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			x.Angle = 0;
			x.DeltaAngle = 0;
			x.Size = 0;
			x.RandomSeed = Math::XorShift128::CreateInitNumber(std::rand());
		});
	D3D11_SUBRESOURCE_DATA sub = {};
	sub.pSysMem = &tmp;
	hr = dev->CreateBuffer(&CD3D11_BUFFER_DESC(sizeof(VertexParticle) * MaxParticleCount,
		D3D11_BIND_VERTEX_BUFFER | D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS, D3D11_USAGE_DEFAULT, 0, D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS),
		&sub, m_pVertexBufferParticles2.GetAddressOf());

	// GPU �ŏ���������\�����o�b�t�@�B
	hr = dev->CreateBuffer(&CD3D11_BUFFER_DESC(sizeof(VertexParticle) * MaxParticleCount,
		D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS, D3D11_USAGE_DEFAULT, 0, D3D11_RESOURCE_MISC_BUFFER_STRUCTURED, sizeof(VertexParticle)),
		&sub, m_pStructBufferParticles2.GetAddressOf());
	{
		// ���_�o�b�t�@��UAV
		D3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
		uavDesc.Format = DXGI_FORMAT_R32_TYPELESS;
		uavDesc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;
		uavDesc.Buffer.FirstElement = 0;
		uavDesc.Buffer.NumElements = sizeof(VertexParticle) * MaxParticleCount / sizeof(float);
		// MSDN �� API �w���v�ɂ͍\�����o�b�t�@�̏ꍇ�̐����͂��邪�ABAB �̏ꍇ�̐������Ȃ��B
		// �����ADX SDK �t���� BasicCompute11 �T���v���ł� BAB �ł� NumElements ���w�肳��Ă���B
		// BAB �̏ꍇ�A4�o�C�g�P�ʂł̗v�f�����w�肷��΂悢�炵���B
		uavDesc.Buffer.Flags = D3D11_BUFFER_UAV_FLAG_RAW;

		hr = dev->CreateUnorderedAccessView(m_pVertexBufferParticles2.Get(), &uavDesc, m_pVertexBufferParticles2UAV.GetAddressOf());
	}
	// �\���o�b�t�@��SRV,UAV
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
	srvDesc.Format = DXGI_FORMAT_UNKNOWN;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFEREX; // D3D11_SRV_DIMENSION_BUFFER �ł̓_���炵���H
	srvDesc.BufferEx.FirstElement = 0;
	srvDesc.BufferEx.NumElements = MaxParticleCount;
	hr = dev->CreateShaderResourceView(m_pStructBufferParticles2.Get(), &srvDesc, m_pStructBufferParticles2SRV.GetAddressOf());
	
	D3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
	uavDesc.Format = DXGI_FORMAT_UNKNOWN;
	uavDesc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;
	uavDesc.Buffer.FirstElement = 0;
	uavDesc.Buffer.NumElements = MaxParticleCount;

	hr = dev->CreateUnorderedAccessView(m_pStructBufferParticles2.Get(), &uavDesc, m_pStructBufferParticles2UAV.GetAddressOf());
	
}

void GPUParticle::Uninit()
{
}

void GPUParticle::Update()
{
}

void GPUParticle::Draw()
{
	auto d = DirectXGraphics::GetInstance().GetDeviceContext();
	UpdateCBuffer(d, m_pConstBufferCommon.Get(), &m_CommonHost);
	ID3D11Buffer* vbs[] =
	{ m_pVertexBufferParticles2.Get() };
	UINT strides[] =
	{ sizeof(VertexParticle) };
	const UINT offsets[] =
	{ 0 };
	ID3D11Buffer* cbs[] =
	{ m_pConstBufferCommon.Get() };
	ID3D11UnorderedAccessView* uavs[] =
	{
		m_pVertexBufferParticles2UAV.Get(),
	};


	d->CSSetConstantBuffers(0, ARRAYSIZE(cbs), cbs);
	d->CSSetShader(m_pComputeShaderParticle.Get(), nullptr, 0);
	d->CSSetUnorderedAccessViews(0, ARRAYSIZE(uavs), uavs, nullptr);

	// �I���W�i���̃v���O�����ł́A���[�J�� �O���[�v �T�C�Y�ɒ��r���[�� 100 �Ƃ��������g���Ă������A
	// �ʏ��2�ׂ̂���i���� 32 �̔{���j���g���B
	// �Ƃ����̂� NVIDIA �ɂ� 32 threads/unit �𑩂˂� WARP�AAMD �ɂ� 64 threads/unit �𑩂˂� WAVEFRONT �Ƃ����T�O������̂ŁA
	// ���̔{���ɍ��킹�Ă������ق����������ǂ��Ȃ邱�Ƃ������B
	// Parallel Reduction �Ȃǂ̕���A���S���Y����2�ׂ̂���̃u���b�N �T�C�Y���g���B
	// �܂��A�O���[�v���L�������⃌�W�X�^���Ƃ̌��ˍ����ɂ��Ȃ邪�A
	// �O���[�v �T�C�Y�� 256, 512, 1024 �Ȃǂɂ��� Occupancy �����߂��ق����������ǂ��Ȃ邱�Ƃ������B
	// �R���s���[�g �V�F�[�_�[�̓X���b�h �O���[�v �T�C�Y�⋤�L�������Ȃǃn�[�h�E�F�A �A�[�L�e�N�`���ɖ��ڂɊւ��@�\�������A
	// OpenCL �� CUDA ���l�Ƀv���O�����̐݌v��p�����[�^����Ő��\���傫���ς�邽�߁A
	// �K�؂ȃ`���[�j���O���s�Ȃ��ɂ́i�]���̃O���t�B�b�N�X �v���O���~���O�ȏ�Ɂj�n�[�h�E�F�A�Ɋւ���[���m�����K�v�ƂȂ�B
	// cf. Kernel Occupancy of OpenCL or CUDA.

	// 1�X���b�h��1�p�[�e�B�N���݂̂���������������A�����̃p�[�e�B�N���������������ق����p�t�H�[�}���X���オ��₷���͗l�H
	// �p�[�e�B�N���̏������݂̂��s�Ȃ��X���b�h���Ȃ������ƂŁA���[�N �o�����X�𒲐��ł���H

	// �p�[�e�B�N���������^�X�N ���j�b�g �T�C�Y�Ŋ���؂�Ȃ��ꍇ�A�p�[�e�B�N���������������X���b�h���N�����邱�ƂɂȂ�B
	// �]�����X���b�h�͓��I����ō�Ƃ������Ȃ��悤�ɂ���B
	// http://wlog.flatlib.jp/item/1425
	//const UINT dispatchX = UINT(std::ceil(float(MaxParticleCount) / float(MY_CS_LOCAL_GROUP_SIZE * MY_CS_PARTICLES_NUM_PER_THREAD)));
	//d->Dispatch(dispatchX, 1, 1);

	// UAV �X���b�g (InOut) �����Z�b�g�B
	uavs[0] = nullptr;
	d->CSSetUnorderedAccessViews(0, ARRAYSIZE(uavs), uavs, nullptr);

	d->VSSetConstantBuffers(0, ARRAYSIZE(cbs), cbs);
#ifdef USE_SB_PARTICLE
	d->VSSetShader(m_pVertexShaderParticle2SB.Get(), nullptr, 0);
	d->VSSetShaderResources(0, ARRAYSIZE(srvs), srvs);
#else
	d->VSSetShader(m_pVertexShaderParticle2.Get(), nullptr, 0);
#endif
	d->GSSetConstantBuffers(0, ARRAYSIZE(cbs), cbs);
	d->GSSetShader(m_pGeometryShaderParticle.Get(), nullptr, 0);
	d->PSSetConstantBuffers(0, ARRAYSIZE(cbs), cbs);
	d->PSSetShader(m_pPixelShaderParticle.Get(), nullptr, 0);
	//d->PSSetSamplers(0, ARRAYSIZE(samplers), samplers);
	//d->PSSetShaderResources(0, ARRAYSIZE(srvs), srvs);

	//d->OMSetRenderTargets(ARRAYSIZE(rtvs), rtvs, nullptr);
	d->IASetInputLayout(m_pVertexInputLayoutParticle2.Get());
	d->IASetVertexBuffers(0, ARRAYSIZE(vbs), vbs, strides, offsets);
	d->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);
	// �\�����o�b�t�@���g���ꍇ�A���_�o�b�t�@�̓_�~�[���́B���ۂ̃p�[�e�B�N�����͍\�����o�b�t�@�ɂĊǗ�����Ă���B
	// ���_���p�[�e�B�N���̐������p�ӂ��Ă������@�ɔ�ׂ�ƁA�C���X�^���X�`��͒x���Ȃ�͗l�B
#if defined(USE_SB_PARTICLE) && defined(USE_INSTANCE_ID_FOR_PARTICLE_DRAW)
	d->DrawInstanced(1, MaxParticleCount, 0, 0);
#else
	d->Draw(MaxParticleCount, 0);
#endif

#ifdef USE_SB_PARTICLE
	// SRV �X���b�g (In) �����Z�b�g�B
	srvs[1] = nullptr;
	d->VSSetShaderResources(0, ARRAYSIZE(srvs), srvs);
	d->PSSetShaderResources(0, ARRAYSIZE(srvs), srvs);
#else
	// VB �X���b�g (In) �����Z�b�g�B
	vbs[0] = nullptr;
	strides[0] = 0;
	d->IASetVertexBuffers(0, ARRAYSIZE(vbs), vbs, strides, offsets);
#endif

	auto& spawnTargetParticleIndex = m_CommonHost.UniSpawnTargetParticleIndex;
	spawnTargetParticleIndex = (spawnTargetParticleIndex + 1) % MaxParticleCount;
}

