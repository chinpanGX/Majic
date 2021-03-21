/*-------------------------------------------------------------
	
	[DirectXGraphics.h]
	Author : 出合翔太

	DirectX関連の処理

--------------------------------------------------------------*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#include <stdio.h>
#include <windows.h>
#include <wrl/client.h>
#include <vector>
#include <array>
#include <memory>
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

#include "ConstantBuffer.h"
#include "BlendMode.h"

namespace Resource
{
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

}

class DirectXGraphics : public Singleton<DirectXGraphics>
{
	friend Singleton<DirectXGraphics>;
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
public:
	void Begin();
	void End();
	void SetDepthEnable(bool Enable);
	void SetWorldViewProjection2D();
	void SetWorldMatrix(D3DXMATRIX * WorldMatrix);
	void SetViewMatrix(D3DXMATRIX * ViewMatrix);
	void SetProjectionMatrix(D3DXMATRIX * ProjectionMatrix);
	void SetMaterial(Resource::Material Material);
	void SetLight(Resource::Light Light);
	void SetCameraPosition(D3DXVECTOR3 CameraPosition);
	void SetParameter(D3DXVECTOR4 Parameter);
	
	ID3D11Device* GetDevice() { return m_Device.Get(); }
	ID3D11DeviceContext* GetDeviceContext() { return m_ImmediateContext.Get(); }

protected:
	DirectXGraphics();
	~DirectXGraphics() {}
private:
	std::unique_ptr<class ConstantBuffer>  m_ConstantBuffer;
	std::array<std::unique_ptr<class BlendMode>,BlendMode::EMode::NUM_MAX> m_BlendMode;
	ComPtr<ID3D11Device>			m_Device;
	ComPtr<ID3D11DeviceContext>		m_ImmediateContext;
	ComPtr<IDXGISwapChain>			m_SwapChain;
	ComPtr<ID3D11RenderTargetView>	m_RenderTargetView;
	ComPtr<ID3D11DepthStencilView>	m_DepthStencilView;
	ComPtr<ID3D11DepthStencilState>	m_DepthStateEnable;
	ComPtr<ID3D11DepthStencilState>	m_DepthStateDisable;
};
