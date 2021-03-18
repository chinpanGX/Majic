/*-------------------------------------------------------------

	[Particle.h]
	Author : �o���đ�

	�p�[�e�B�N���̏���
	�G�~�b�^�[����ɐ�������

--------------------------------------------------------------*/
#pragma once
#include "GameObject.h"

class Particle : public GameObject
{
public:
	Particle()
	{
		m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Scale = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Gravity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
		m_SizeWidth = 50.0f;
		m_sizeHeight = 50.0f;
		m_Life = 0;
		m_Use = false;
	}
	~Particle(){}
	D3DXVECTOR3 m_Velocity; // ���x�@�@position�ɉ��Z
	D3DXVECTOR3 m_Gravity;  // �d�͒l�@Velocity�ɉ��Z����
	D3DCOLOR m_Color;		// �F
	float m_SizeWidth;		// ����
	float m_sizeHeight;		// �c��
	int32_t	m_Life;			// �L������	
	bool m_Use;				// �L�����ǂ���
};

