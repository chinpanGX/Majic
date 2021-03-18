/*-----------------------------------------------------------

	[Prefabs.h]
	Author : 出合翔太

	[説明]
	テクスチャ、シェーダーのロード、アンロード

------------------------------------------------------------*/
#pragma once
#include "Loader.h"
#include <memory>

class PrefabsBase
{
protected:
	int32_t m_Size; // プレハブの数

public:
	virtual void Load(Resource& dx) = 0;
	virtual void Unload() = 0;
};

namespace Prefabs
{
	// Textureのプレハブ
	class Texture : public PrefabsBase
	{
	public:
		enum ID : int32_t
		{
			FADE,
			TATILE_BG,
			GAME_BG,
			FIELD,
			WAFFURU,
			EFFECT,
			MAX
		};
		Texture() { m_Size = ID::MAX; }
		void Load(Resource& dx)override;
		void Unload()override;
		ID3D11ShaderResourceView* GetTexture(int32_t Id);
	private:
		std::unique_ptr<Loader::Texture[]> m_Texture;
	};

	// 頂点シェーダー
	class VertexShader : public PrefabsBase
	{
	public:
		enum ID : int32_t
		{
			DEFAULT,
			MAPPING,
			MAX
		};
		VertexShader() { m_Size = ID::MAX; }
		void Load(Resource& dx)override;
		void Unload()override;
		ID3D11VertexShader* GetVertexShader(int32_t Id);
		ID3D11InputLayout* GetInputLayout(int32_t Id);
	private:
		std::unique_ptr<Loader::VertexShader[]> m_VertexShader;
	};

	// ピクセルシェーダー
	class PixelShader : public PrefabsBase
	{
	public:
		enum ID : int32_t
		{
			DEFAULT,
			MAPPING,
			MAX
		};
		PixelShader() { m_Size = ID::MAX; }
		void Load(Resource& dx)override;
		void Unload()override;
		ID3D11PixelShader* GetPixelShader(int32_t Id);
	private:
		std::unique_ptr<Loader::PixelShader[]> m_PixelShader;
	};
}

