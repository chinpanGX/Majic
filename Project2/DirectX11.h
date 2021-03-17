/*---------------------------------------------------------

	[DirectX11.h]
	Author : �o���đ�

	[����]
	namespace->DirectX11
	Manager::DirectX11�ɕK�v�Ȃ��̂��Ǘ�����N���X

----------------------------------------------------------*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#include <stdio.h>
#include <windows.h>
#include <assert.h> // �G���[����
#include <iostream>
#include <wrl/client.h>
#include "Singleton.h"

#pragma warning(disable:4005)
#pragma warning(push)

// DirectX��API
#include <d3d11.h>
#include <d3dx9.h>
#include <d3dx11.h>
// �Z�p���C�u����
#include <DirectXMath.h>
// �V�F�[�_�[�̃R���p�C��
#include <d3dcompiler.h>

#pragma warning(pop)

#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"d3dcompiler.lib")

// �����^�C���G���[�}�N��
#define STRINGFY(s)  #s
#define TO_STRING(x) STRINGFY(x)
#define FILE_PREFIX __FILE__ "(" TO_STRING(__LINE__) "): " 
#define ThrowIfFailed(hr, msg) Utility::CheckResultCode( hr, FILE_PREFIX msg)

// DirectX11
namespace DirectX11
{
	struct Vertex
	{
		D3DXVECTOR3 Position;
		D3DXVECTOR3 Normal;
		D3DXVECTOR4 Diffuse;
		D3DXVECTOR2 TexCoord;
	};

	// �}�e���A���\����
	struct Material
	{
		D3DXCOLOR	Ambient;
		D3DXCOLOR	Diffuse;
		D3DXCOLOR	Specular;
		D3DXCOLOR	Emission;
		float		Shininess;
		float		Dummy[3];//16byte���E�p
	};

	// �}�e���A���\����
	struct ModelMaterial
	{
		Material		Material;
		class Texture*	Texture;
	};

	// �`��T�u�Z�b�g�\����
	struct SubSet
	{
		ModelMaterial	Material;
		int32_t	StartIndex;
		int32_t	IndexNum;
	};

	// ���C�g�\����
	struct Light
	{
		BOOL		Enable;
		BOOL		Dummy[3];//16byte���E�p
		D3DXVECTOR4	Direction;
		D3DXCOLOR	Diffuse;
		D3DXCOLOR	Ambient;
	};

	// �Ǘ������X
	class Manager : public Singleton<Manager>
	{
		friend Singleton<Manager>;
	public:
		void Init();
		void Uninit();
		void Begin();
		void End();
		void SetDepthEnable(bool Enable);
		void SetWorldViewProjection2D();
		void SetWorldMatrix(D3DXMATRIX * WorldMatrix);
		void SetViewMatrix(D3DXMATRIX * ViewMatrix);
		void SetProjectionMatrix(D3DXMATRIX * ProjectionMatrix);
		void SetMaterial(Material Material);
		void SetLight(Light Light);
		void SetCameraPosition(D3DXVECTOR3 CameraPosition);
		void SetParameter(D3DXVECTOR4 Parameter);

		// �V�F�[�_�[����
		void CreateVertexShader(ID3D11VertexShader** VertexShader, ID3D11InputLayout** InputLayout, const char* FileName);
		void CreatePixelShader(ID3D11PixelShader** PixelShader, const char* FileName);

		ID3D11Device* GetDevice() { return m_Device; }
		ID3D11DeviceContext* GetDeviceContext() { return m_ImmediateContext; }
	protected:
		Manager() {}
		virtual ~Manager(){}
	private:
		ID3D11Device*			m_Device = nullptr;
		ID3D11DeviceContext*		m_ImmediateContext = nullptr;
		IDXGISwapChain*			m_SwapChain = nullptr;
		ID3D11RenderTargetView*	m_RenderTargetView = nullptr;
		ID3D11DepthStencilView*	m_DepthStencilView = nullptr;
		ID3D11Buffer*			m_WorldBuffer = nullptr;
		ID3D11Buffer*			m_ViewBuffer = nullptr;
		ID3D11Buffer*			m_ProjectionBuffer = nullptr;
		ID3D11Buffer*			m_MaterialBuffer = nullptr;
		ID3D11Buffer*			m_LightBuffer = nullptr;
		ID3D11Buffer*			m_CameraBuffer = nullptr;
		ID3D11Buffer*			m_ParameterBuffer = nullptr;
		ID3D11DepthStencilState*	m_DepthStateEnable = nullptr;
		ID3D11DepthStencilState*	m_DepthStateDisable = nullptr;
	};
}

namespace Utility
{
	class Exception : public std::runtime_error
	{
	public:
		Exception(const std::string& msg) : std::runtime_error(msg.c_str()) {}
	};

	inline void CheckResultCode(HRESULT hr, const std::string& errorMsg)
	{
		if (FAILED(hr))
		{
			throw Exception(errorMsg);
		}
	}
}



