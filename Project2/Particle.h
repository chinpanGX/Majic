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
	D3DXVECTOR3 m_Velocity; // ���x�@�@position�ɉ��Z
	D3DXVECTOR3 m_Gravity;  // �d�͒l�@Velocity�ɉ��Z����
	D3DCOLOR m_Color;		// �F
};

