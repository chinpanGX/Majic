/*-------------------------------------------------------------

	[Particle.h]
	Author : �o���đ�

	�p�[�e�B�N���̏���
	�G�~�b�^�[����ɐ�������

--------------------------------------------------------------*/
#pragma once
#include "GameObject.h"
#include "Math.h"

class VertexParticle final
{
	D3DXVECTOR3 Position;
	D3DXVECTOR3 Velocity;
	float Angle;
	float DeltaAngle;
	float Size;
	uint32_t Life;
	DirectX::XMUINT4 RandomSeed;
};

class BufferCommon final
{
	uint32_t UniSpawnTargetParticleIndex;
	D3DXVECTOR3 UniParticleVelocity;
	float UniMaxAngularVelocity; // radian
	uint32_t UniMaxParticleCount;
	float UniParticleInitSize;
	D3DXVECTOR2 Dummy0;
};

class GPUParticle
{

};

class Particle
{
public:
	Particle();
	~Particle();
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;
	//D3DXVECTOR3 m_Gravity;  // �d�͒l�@Velocity�ɉ��Z����
	D3DXCOLOR m_Color;		// �F
	int32_t	m_Life;			// �L������	
	bool m_Use;				// �L�����ǂ���
};
;