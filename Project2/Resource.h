/*---------------------------------------------------------

	[Resource.h]
	Author : 出合翔太

	[説明]
	Resourceに必要なものを管理するクラス

----------------------------------------------------------*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#include <stdio.h>
#include <windows.h>
#include <assert.h> // エラー処理
#include <iostream>
#include <wrl/client.h>
#include "Singleton.h"

#pragma warning(disable:4005)
#pragma warning(push)

// DirectXのAPI
#include <d3d11.h>
#include <d3dx9.h>
#include <d3dx11.h>
// 算術ライブラリ
#include <DirectXMath.h>
// シェーダーのコンパイラ
#include <d3dcompiler.h>

#pragma warning(pop)

#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"d3dcompiler.lib")

// ランタイムエラーマクロ
#define STRINGFY(s)  #s
#define TO_STRING(x) STRINGFY(x)
#define FILE_PREFIX __FILE__ "(" TO_STRING(__LINE__) "): " 
#define ThrowIfFailed(hr, msg) Utility::CheckResultCode( hr, FILE_PREFIX msg)


// 管理くラス
class Resource : public Singleton<Resource>
{
	friend Singleton<Resource>;
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
public:
	class Vertex
	{
	public:
		D3DXVECTOR3 Position;
		D3DXVECTOR3 Normal;
		D3DXVECTOR4 Diffuse;
		D3DXVECTOR2 TexCoord;
	};

	// マテリアル構造体
	class Material
	{
	public:
		D3DXCOLOR	Ambient;
		D3DXCOLOR	Diffuse;
		D3DXCOLOR	Specular;
		D3DXCOLOR	Emission;
		float		Shininess;
		float		Dummy[3];//16byte境界用
	};

	// マテリアル構造体
	class ModelMaterial
	{
	public:
		Material		Material;
		class Texture*	Texture;
	};

	// 描画サブセット構造体
	class SubSet
	{
	public:
		ModelMaterial	Material;
		int32_t	StartIndex;
		int32_t	IndexNum;
	};

	// ライト構造体
	class Light
	{
	public:
		BOOL		Enable;
		BOOL		Dummy[3];//16byte境界用
		D3DXVECTOR4	Direction;
		D3DXCOLOR	Diffuse;
		D3DXCOLOR	Ambient;
	};
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

	// シェーダー生成
	void CreateVertexShader(ID3D11VertexShader** VertexShader, ID3D11InputLayout** InputLayout, const char* FileName);
	void CreatePixelShader(ID3D11PixelShader** PixelShader, const char* FileName);

	ID3D11Device* GetDevice() { return m_Device.Get(); }
	ID3D11DeviceContext* GetDeviceContext() { return m_ImmediateContext.Get(); }
protected:
	Resource();
	~Resource(){}
private:
	ComPtr<ID3D11Device>			m_Device = nullptr;
	ComPtr<ID3D11DeviceContext>		m_ImmediateContext = nullptr;
	ComPtr<IDXGISwapChain>			m_SwapChain = nullptr;
	ComPtr<ID3D11RenderTargetView>	m_RenderTargetView = nullptr;
	ComPtr<ID3D11DepthStencilView>	m_DepthStencilView = nullptr;
	ComPtr<ID3D11Buffer>			m_WorldBuffer = nullptr;
	ComPtr<ID3D11Buffer>			m_ViewBuffer = nullptr;
	ComPtr<ID3D11Buffer>			m_ProjectionBuffer = nullptr;
	ComPtr<ID3D11Buffer>			m_MaterialBuffer = nullptr;
	ComPtr<ID3D11Buffer>			m_LightBuffer = nullptr;
	ComPtr<ID3D11Buffer>			m_CameraBuffer = nullptr;
	ComPtr<ID3D11Buffer>			m_ParameterBuffer = nullptr;
	ComPtr<ID3D11DepthStencilState>	m_DepthStateEnable = nullptr;
	ComPtr<ID3D11DepthStencilState>	m_DepthStateDisable = nullptr;
};

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



