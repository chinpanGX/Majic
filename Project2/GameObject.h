/*----------------------------------------------

	[GameObject.h]
	Author : 出合翔太

	[説明]
	GameObject 
		: すべてのゲームオブジェクトに対する基底クラス
			オブジェクトが有効化どうかのフラグ（Destory）を持つ

-----------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"

class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0 ;

	void SetDestroy() { m_Destroy = true; }
	bool Destroy()
	{
		if (m_Destroy == true)
		{
			Uninit();
			delete this;
			return true;
		}
		else
		{
			return false;
		}
	}
	// ベクトルの方向
	enum Vector : int
	{
		Reight,
		Left,
		Up,
		Down,
		Forward,
		Backward
	};

	// プロパティ
	D3DXVECTOR3 GetPosition()const { return m_Position; }
	D3DXVECTOR3 GetRotation()const { return m_Rotation; }
	D3DXVECTOR3 GetScale()const { return m_Scale; }
	void SetPosition(D3DXVECTOR3 Position) { m_Position = Position; }
	void SetRotation(D3DXVECTOR3 Rotation) { m_Rotation = Rotation; }
	void SetScale(D3DXVECTOR3 Scale) { m_Scale = Scale; }
	// 前方向ベクトルを返す
	D3DXVECTOR3 GetForward()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
		D3DXVECTOR3 forward;
		//前方向ベクトル
		forward.x = rot._31;
		forward.y = rot._32;
		forward.z = rot._33;
		return forward;
	}

	// 指定した方向ベクトルを返す
	D3DXVECTOR3 GetVector(Vector v)
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
		D3DXVECTOR3 vector;
		switch (v)
		{
			// 左右
		case 0:
		case 1:
			vector.x = rot._11;
			vector.y = rot._12;
			vector.z = rot._13;
			break;
			// 上下
		case 2:
		case 3:
			vector.x = rot._21;
			vector.y = rot._22;
			vector.z = rot._23;
			break;
			// 前後
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
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;
	bool m_Destroy = false;
};
