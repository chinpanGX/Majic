/*-------------------------------------------------------------

	[Transform.h]
	Author : �o���đ�

	[����]
	Object�̈ʒu�A��]�A�傫���̏�������

-------------------------------------------------------------*/
#pragma once
#include "DirectX11.h"

class Transform
{
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
public:
	Transform() : m_Position(0.0f, 0.0f, 0.0f), m_Rotation(0.0f, 0.0f, 0.0f), m_Scale(1.0f, 1.0f, 1.0f) {};
	~Transform() {};
	
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

private:
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;
};

