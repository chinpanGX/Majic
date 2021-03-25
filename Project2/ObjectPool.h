/*-----------------------------------------------------------

	[ObjectPool.h]
	Author : 出合翔太

	[説明]
	アセットのロード、アンロード、管理を行う
	スタティックにするなら、関数だけで良くね？

------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"
#include "PrefabsShader.h"
#include "PrefabsTexture.h"

namespace ObjectPool
{
	// メモリの確保
	void Init();
}

// テクスチャのGetter / Setter
ID3D11ShaderResourceView* GetTexture(int32_t Id);
void SetTexture(DirectXGraphics& dx, int slot, int32_t Id); // slot = 設定するスロット、ID = 格納ID

// 頂点シェーダー
void SetVertexShader(DirectXGraphics& dx, int32_t Id); 
void SetInputLayout(DirectXGraphics& dx, int32_t Id);
// ピクセルシェーダー
void SetPixelShader(DirectXGraphics& dx, int32_t Id);
// ジオメトリシェーダー
void SetGeometryShader(DirectXGraphics& dx, int32_t Id);
// コンピュートシェーダー
void SetComputeShader(DirectXGraphics& dx, int32_t Id);