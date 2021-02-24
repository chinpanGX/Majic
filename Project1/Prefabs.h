/*-----------------------------------------------------------

	[Prefabs.h]
	Author : 出合翔太

	[説明]
	テクスチャ、シェーダーのロード、アンロード

------------------------------------------------------------*/
#pragma once
#include "Loader.h"

class PrefabsBase
{
protected:
	__int32 m_Size; // プレハブの数

public:
	virtual void Load(DirectX11::Manager& dx) = 0;
	virtual void Unload() = 0;
};

namespace Prefabs
{
	// Textureのプレハブ
	class Texture : public PrefabsBase
	{
	public:
		enum ID : unsigned __int32
		{
			FADE,
			TATILE_BG,
			GAME_BG,
			FIELD,
			WAFFURU,
			MAX
		};
		Texture() { m_Size = ID::MAX; }
		void Load(DirectX11::Manager& dx)override;
		void Unload()override;
		ID3D11ShaderResourceView* GetTexture(unsigned __int32 Id);
	private:
		Loader::Texture* m_Texture;
	};

	// 頂点シェーダー
	class VertexShader : public PrefabsBase
	{
	public:
		enum ID : unsigned __int32
		{
			DEFAULT,
			MAPPING,
			MAX
		};
		VertexShader() { m_Size = ID::MAX; }
		void Load(DirectX11::Manager& dx)override;
		void Unload()override;
		ID3D11VertexShader* GetVertexShader(unsigned __int32 Id);
		ID3D11InputLayout* GetInputLayout(unsigned __int32 Id);
	private:
		Loader::VertexShader* m_VertexShader;
	};

	// ピクセルシェーダー
	class PixelShader : public PrefabsBase
	{
	public:
		enum ID : unsigned __int32
		{
			DEFAULT,
			MAPPING,
			MAX
		};
		PixelShader() { m_Size = ID::MAX; }
		void Load(DirectX11::Manager& dx)override;
		void Unload()override;
		ID3D11PixelShader* GetPixelShader(unsigned __int32 Id);
	private:
		Loader::PixelShader* m_PixelShader;
	};
}

