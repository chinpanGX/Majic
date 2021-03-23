/*-------------------------------------------------------------
	
	[Effect.h]
	Author : èoçá„ƒëæ

--------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"

class Effect
{
public:

private:
};

struct VertexPraticle
{
	D3DXVECTOR3 m_Position;
	D3DXVECTOR2	m_TexCoord;
};

struct ParticleCompute
{
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Velocity;
	int32_t m_Life;
};
