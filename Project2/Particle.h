/*-------------------------------------------------------------

	[Particle.h]
	Author : �o���đ�

	�p�[�e�B�N���̏���
	�G�~�b�^�[����ɐ�������

--------------------------------------------------------------*/
#pragma once
#include "GameObject.h"

class Particle
{
public:
	Particle();
	~Particle();
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;
	D3DXVECTOR3 m_Velocity; // ���x�@�@position�ɉ��Z
	D3DXVECTOR3 m_Gravity;  // �d�͒l�@Velocity�ɉ��Z����
	D3DXCOLOR m_Color;		// �F
	float m_SizeWidth;		// ����
	float m_SizeHeight;		// �c��
	int32_t	m_Life;			// �L������	
	bool m_Use;				// �L�����ǂ���
};
;