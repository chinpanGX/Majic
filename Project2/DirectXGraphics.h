/*-------------------------------------------------------------
	
	[DirectXGraphics.h]
	Author : 出合翔太

	DirectX関連の処理

--------------------------------------------------------------*/
#pragma once
#include "stdafx.h"
#include "Singleton.h"
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

namespace
{
	// コンスタントバッファの更新
	template<typename T>
	inline void UpdateCBuffer(ID3D11DeviceContext * pDeviceContext, ID3D11Buffer * pBuffer, const T & Src)
	{
		pDeviceContext->UpdateSubresource(pBuffer, 0, nullptr, Src, 0, 0);
	}
}

class DirectXGraphics final : public Singleton<DirectXGraphics>
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

	void SetBlendState(BlendMode::EMode Mode);
	
	ID3D11Device* GetDevice() const;
	ID3D11DeviceContext* GetDeviceContext() const;

protected:
	DirectXGraphics();
	~DirectXGraphics();
private:
	// 初期化処理
	void InitDevice();
	void InitState();

	std::array<std::unique_ptr<class BlendMode>, BlendMode::NUM_MAX> m_BlendMode;
	std::unique_ptr<class ConstantBuffer>  m_ConstantBuffer;
	ComPtr<ID3D11Device>			m_Device;
	ComPtr<ID3D11DeviceContext>		m_ImmediateContext;
	ComPtr<IDXGISwapChain>			m_SwapChain;
	ComPtr<ID3D11RenderTargetView>	m_RenderTargetView;
	ComPtr<ID3D11DepthStencilView>	m_DepthStencilView;
	ComPtr<ID3D11DepthStencilState>	m_DepthStateEnable;
	ComPtr<ID3D11DepthStencilState>	m_DepthStateDisable;
};
