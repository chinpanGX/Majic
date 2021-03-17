/*-----------------------------------------------
	
	[Actor.h]
	Author : �o���đ�

	[����]
	Actor : GameObject�N���X���p��
	2D�`��Ɏg��Renderer�N���X������

------------------------------------------------*/
#pragma once
#include "GameObject.h"
#include "Renderer.h"

class Actor : public GameObject
{
public:
	Actor() {}
	virtual ~Actor() {}
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	Renderer GetRender()
	{
		return m_Renderer;
	}

	// �x�N�g���̕���
	enum Vector : int
	{
		Reight,
		Left,
		Up,
		Down,
		Forward,
		Backward
	};

	// �v���p�e�B
	D3DXVECTOR3 GetPosition()const { return m_Position; }
	D3DXVECTOR3 GetRotation()const { return m_Rotation; }
	D3DXVECTOR3 GetScale()const { return m_Scale; }
	void SetPosition(D3DXVECTOR3 Position) { m_Position = Position; }
	void SetRotation(D3DXVECTOR3 Rotation) { m_Rotation = Rotation; }
	void SetScale(D3DXVECTOR3 Scale) { m_Scale = Scale; }
	// �O�����x�N�g����Ԃ�
	D3DXVECTOR3 GetForward()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
		D3DXVECTOR3 forward;
		//�O�����x�N�g��
		forward.x = rot._31;
		forward.y = rot._32;
		forward.z = rot._33;
		return forward;
	}

	// �w�肵�������x�N�g����Ԃ�
	D3DXVECTOR3 GetVector(Vector v)
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
		D3DXVECTOR3 vector;
		switch (v)
		{
			// ���E
		case 0:
		case 1:
			vector.x = rot._11;
			vector.y = rot._12;
			vector.z = rot._13;
			break;
			// �㉺
		case 2:
		case 3:
			vector.x = rot._21;
			vector.y = rot._22;
			vector.z = rot._23;
			break;
			// �O��
		case 4:
		case 5:
			vector.x = rot._31;
			vector.y = rot._32;
			vector.z = rot._33;
			break;
		}

		if (v % 2 == 1)
		{
			vector *= -1;
		}
		return vector;
	}
protected:
	Renderer m_Renderer;
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;
};

