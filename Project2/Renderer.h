/*-------------------------------------------------------------
	
	[Renderer.h]
	Author : 出合翔太

	[説明]
	Rendererクラス : 2Dの描画に関する処理をまとめる

--------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"

class Renderer
{
public:
	Renderer() : m_Dx(DirectXGraphics::GetInstance()), m_VertexBuffer(nullptr), m_Alpha(1.0f) {};
	~Renderer() {};

	void Init();
	void Init(ID3D11ShaderResourceView * texture, D3DXVECTOR2 drawPosition, D3DXVECTOR2 drawSize, D3DXVECTOR2 texUpLeft, D3DXVECTOR2 texDownRight, 
		D3DXCOLOR color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), int32_t Id_1 = 0, int32_t Id_2 = 0);

	void Uninit() {};
	void Update() {};

	void Draw(ID3D11ShaderResourceView* texture, 
		D3DXVECTOR2 drawPosition, D3DXVECTOR2 drawSize, D3DXVECTOR2 texUpLeft, D3DXVECTOR2 texDownRight, 
		D3DXCOLOR color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), int32_t Id_1 = 0, int32_t Id_2 = 0);
	void Draw();
	
	void SetAlpha(float alpha) {};
private:
	void CreateVertex(); // 頂点作成
	void DynamicChangeBuffer(D3DXVECTOR2 drawPosition, D3DXVECTOR2 drawSize, D3DXVECTOR2 texUpLeft, D3DXVECTOR2 texDownRight); // バッファの動的変更
	void SetShader(int32_t Id_1 = 0, int32_t Id_2 = 0); // シェーダーのセット

	DirectXGraphics& m_Dx;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_VertexBuffer;
	float m_Alpha;
};

