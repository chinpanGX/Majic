#pragma once
#include "DirectXGraphics.h"

class LoadTexture
{
	template< typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
public:
	LoadTexture();
	~LoadTexture();
	void Load(DirectXGraphics& dx, std::string FileName); // ロード
	
	inline ComPtr<ID3D11ShaderResourceView> GetTexture()const
	{
		return m_Texture;
	}
private:
	ComPtr<ID3D11ShaderResourceView> m_Texture;
};

namespace Prefabs
{
	// Textureのプレハブ
	class Texture final
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
		Texture();
		Texture(DirectXGraphics& dx);
		~Texture();
		ID3D11ShaderResourceView* GetTexture(int32_t Id);
	private:
		static const int32_t m_Size = ID::MAX;
		std::array<std::unique_ptr<LoadTexture>, m_Size> m_Texture;
	};
}
