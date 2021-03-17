/*-----------------------------------------------------------

	[ObjectPool.h]
	Author : 出合翔太

	[説明]
	アセットのロード、アンロード、管理を行う


------------------------------------------------------------*/
#pragma once
#include "Prefabs.h"

// オブジェクトプール
class ObjectPool
{
public:
	static void Init();
	static void Uninit();
	static void Update(Resource& dx, int32_t Id, const char* AnimationName1, const char* AnimationName2, float BlendRate, int Frame);
	static void Draw(Resource& dx, int32_t Id);
	
	// テクスチャのGetter / Setter
	static ID3D11ShaderResourceView* GetTexture(int32_t Id);
	static void SetTexture(Resource& dx, int slot, int32_t Id); // slot = 設定するスロット、ID = 格納ID

	// シェーダーの設定
	static void SetVertexShader(Resource& dx, int32_t Id);
	static void SetInputLayout(Resource& dx, int32_t Id);
	static void SetPixelShader(Resource& dx, int32_t Id);
private:
	static std::unique_ptr<Prefabs::Texture> m_Texture;
	static std::unique_ptr<Prefabs::VertexShader> m_VertexShader;
	static std::unique_ptr<Prefabs::PixelShader> m_PixelShader;
};

