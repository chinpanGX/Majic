/*-------------------------------------------------------------

	[Emitter.h]
	Author : �o���đ�

	�p�[�e�B�N���̐������s��
	�쐬���A�쐬���ԁA�쐬�Ԋu

--------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"
#include "Particle.h"
#include <array>

namespace
{
	const int32_t	m_NumMax = 512;		// �p�[�e�B�N���̍ő吔
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
	// ���_�̍쐬
	void CreateVertex();
	void SetVertex(int32_t Index, float Width, float Height);
	// �p�[�e�B�N���̐ݒ�
	int32_t SetParticle(D3DXVECTOR3 Pos, D3DXVECTOR3 Move, D3DXCOLOR Color);
	// �F�̐ݒ�
	void SetColor(int32_t Index, D3DXCOLOR Color);

	std::array<class Particle, m_NumMax> m_Particle;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_VertexBuffer;
	D3DXMATRIX m_Matrix;
	D3DXVECTOR3 m_BasePostion;	// �����ʒu
	float		m_SizeWidth;	// ��
	float		m_SizeHeight;	// ����
	float		m_Velocity;		// ���x
	float		m_Direction;	// ����
};

