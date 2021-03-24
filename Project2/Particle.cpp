/*-------------------------------------------------------------

	[Particle.h]
	Author : 出合翔太

	パーティクルの処理
	エミッターを基準に生成する

--------------------------------------------------------------*/
#include "Particle.h"
#include "Utility.h"
#include <atldef.h>
#include <algorithm>

/*
using Microsoft::WRL::ComPtr;
HRESULT CreateStructuedBuffer(UINT NumElements, ComPtr<ID3D11Buffer> ppBuffer, ComPtr<ID3D11ShaderResourceView> ppSRV, ComPtr<ID3D11UnorderedAccessView> ppUAV)
{
	// デバイスの取得
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

	// SRVの生成
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_UNKNOWN;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFER;
	srvDesc.Buffer.ElementWidth = NumElements;
	dev->CreateShaderResourceView(*ppBuffer, &srvDesc, ppSRV);

	// UAVの生成
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

	// GPU で書き換える構造化バッファ。
	hr = dev->CreateBuffer(&CD3D11_BUFFER_DESC(sizeof(VertexParticle) * MaxParticleCount,
		D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS, D3D11_USAGE_DEFAULT, 0, D3D11_RESOURCE_MISC_BUFFER_STRUCTURED, sizeof(VertexParticle)),
		&sub, m_pStructBufferParticles2.GetAddressOf());
	{
		// 頂点バッファのUAV
		D3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
		uavDesc.Format = DXGI_FORMAT_R32_TYPELESS;
		uavDesc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;
		uavDesc.Buffer.FirstElement = 0;
		uavDesc.Buffer.NumElements = sizeof(VertexParticle) * MaxParticleCount / sizeof(float);
		// MSDN の API ヘルプには構造化バッファの場合の説明はあるが、BAB の場合の説明がない。
		// ただ、DX SDK 付属の BasicCompute11 サンプルでは BAB でも NumElements が指定されている。
		// BAB の場合、4バイト単位での要素数を指定すればよいらしい。
		uavDesc.Buffer.Flags = D3D11_BUFFER_UAV_FLAG_RAW;

		hr = dev->CreateUnorderedAccessView(m_pVertexBufferParticles2.Get(), &uavDesc, m_pVertexBufferParticles2UAV.GetAddressOf());
	}
	// 構造バッファのSRV,UAV
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
	srvDesc.Format = DXGI_FORMAT_UNKNOWN;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFEREX; // D3D11_SRV_DIMENSION_BUFFER ではダメらしい？
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

	// オリジナルのプログラムでは、ローカル グループ サイズに中途半端な 100 という数が使われていたが、
	// 通常は2のべき乗（特に 32 の倍数）を使う。
	// というのも NVIDIA には 32 threads/unit を束ねる WARP、AMD には 64 threads/unit を束ねる WAVEFRONT という概念があるので、
	// その倍数に合わせておいたほうが効率が良くなることが多い。
	// Parallel Reduction などの並列アルゴリズムも2のべき乗のブロック サイズを使う。
	// また、グループ共有メモリやレジスタ数との兼ね合いにもなるが、
	// グループ サイズを 256, 512, 1024 などにして Occupancy を高めたほうが効率が良くなることが多い。
	// コンピュート シェーダーはスレッド グループ サイズや共有メモリなどハードウェア アーキテクチャに密接に関わる機能が多く、
	// OpenCL や CUDA 同様にプログラムの設計やパラメータ次第で性能が大きく変わるため、
	// 適切なチューニングを行なうには（従来のグラフィックス プログラミング以上に）ハードウェアに関する深い知識が必要となる。
	// cf. Kernel Occupancy of OpenCL or CUDA.

	// 1スレッドに1パーティクルのみを処理させるよりも、複数のパーティクルを処理させたほうがパフォーマンスが上がりやすい模様？
	// パーティクルの初期化のみを行なうスレッドをなくすことで、ワーク バランスを調整できる？

	// パーティクル総数がタスク ユニット サイズで割り切れない場合、パーティクル総数よりも多くスレッドを起動することになる。
	// 余ったスレッドは動的分岐で作業をさせないようにする。
	// http://wlog.flatlib.jp/item/1425
	//const UINT dispatchX = UINT(std::ceil(float(MaxParticleCount) / float(MY_CS_LOCAL_GROUP_SIZE * MY_CS_PARTICLES_NUM_PER_THREAD)));
	//d->Dispatch(dispatchX, 1, 1);

	// UAV スロット (InOut) をリセット。
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
	// 構造化バッファを使う場合、頂点バッファはダミー入力。実際のパーティクル情報は構造化バッファにて管理されている。
	// 頂点をパーティクルの数だけ用意しておく方法に比べると、インスタンス描画は遅くなる模様。
#if defined(USE_SB_PARTICLE) && defined(USE_INSTANCE_ID_FOR_PARTICLE_DRAW)
	d->DrawInstanced(1, MaxParticleCount, 0, 0);
#else
	d->Draw(MaxParticleCount, 0);
#endif

#ifdef USE_SB_PARTICLE
	// SRV スロット (In) をリセット。
	srvs[1] = nullptr;
	d->VSSetShaderResources(0, ARRAYSIZE(srvs), srvs);
	d->PSSetShaderResources(0, ARRAYSIZE(srvs), srvs);
#else
	// VB スロット (In) をリセット。
	vbs[0] = nullptr;
	strides[0] = 0;
	d->IASetVertexBuffers(0, ARRAYSIZE(vbs), vbs, strides, offsets);
#endif

	auto& spawnTargetParticleIndex = m_CommonHost.UniSpawnTargetParticleIndex;
	spawnTargetParticleIndex = (spawnTargetParticleIndex + 1) % MaxParticleCount;
}

