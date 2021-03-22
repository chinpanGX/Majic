/*-------------------------------------------------------------

	[Emitter.h]
	Author : 出合翔太

	パーティクルの生成を行う
	作成数、作成時間、作成間隔

--------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"
#include "Particle.h"
#include <array>

namespace
{
	const int32_t	m_NumMax = 512;		// パーティクルの最大数
}

class Emitter
{
public:
	Emitter();
	~Emitter();
	void Uninit();
	void Update();
	void Draw();
private:
	// 頂点の作成
	void CreateVertex();
	void SetVertex(int32_t Index, float Width, float Height);
	// パーティクルの設定
	int32_t SetParticle(D3DXVECTOR3 Pos, D3DXVECTOR3 Move, D3DXCOLOR Color);
	// 色の設定
	void SetColor(int32_t Index, D3DXCOLOR Color);

	std::array<class Particle, m_NumMax> m_Particle;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_VertexBuffer;
	D3DXMATRIX m_Matrix;
	D3DXVECTOR3 m_BasePostion;	// 発生位置
	float		m_SizeWidth;	// 幅
	float		m_SizeHeight;	// 高さ
	float		m_Velocity;		// 速度
	float		m_Direction;	// 方向
};

