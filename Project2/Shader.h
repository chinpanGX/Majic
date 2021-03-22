/*-------------------------------------------------------------

	[Shader.h]
	Author : �o���đ�

	�V�F�[�_�[�̊Ǘ�

--------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"
#include <string>

namespace Shader
{
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
	// ���_�V�F�[�_�[
	class VertexShader
	{
	public:
		VertexShader();
		~VertexShader();
		void Load(DirectXGraphics & dx, std::string FileName);
		ComPtr<ID3D11VertexShader> GetVertexShader() const;
		ComPtr<ID3D11InputLayout> GetInputLayout() const;
	private:
		// ����
		void CreateVertexShader(DirectXGraphics & dx, ID3D11VertexShader ** Shader, ID3D11InputLayout ** InputLayout, std::string FileName);

		ComPtr<ID3D11VertexShader> m_VertexShader;
		ComPtr<ID3D11InputLayout> m_InputLayout;
	};

	// �s�N�Z���V�F�[�_�[
	class PixelShader
	{
	public:
		PixelShader();
		~PixelShader();
		void Load(DirectXGraphics & dx, std::string FileName);
		ComPtr<ID3D11PixelShader> GetPixelShader() const;
	private:
		// ����
		void CreatePixelShader(DirectXGraphics& dx, ID3D11PixelShader** Shader, std::string FileName);

		ComPtr<ID3D11PixelShader> m_PixelShader;
	};

	// �R���s���[�g�V�F�[�_�[
	class ComputeShader
	{
	public:
		ComputeShader();
		~ComputeShader();
		void Load(DirectXGraphics& dx, std::string FileName);
		ComPtr<ID3D11ComputeShader> GetComputeShader() const;
	private:
		void Create(DirectXGraphics& dx, ID3D11ComputeShader** Shader, std::string FileName);
		ComPtr<ID3D11ComputeShader> m_Computeshader;
	};

	// SRV��UAV�ō\�����o�b�t�@���쐬���邽�߂̃w���p�[�֐�
	template<typename T>
	HRESULT CreateStructuedBuffer(UINT NumElements, ID3D11Buffer** ppBuffer, ID3D11ShaderResourceView** ppSRV, ID3D11UnorderedAccessView** ppUAV, const T* pInitData = nullptr)
	{
		// �f�o�C�X�̎擾
		auto& dev = Resource::GetInstance().GetDevice();

		HRESULT hr = S_OK;

		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.ByteWidth = NumElements * sizeof(T);
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
};

