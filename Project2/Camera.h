/*-------------------------------------------------------------
	
	[Camera.h]
	Author : �o���đ�

--------------------------------------------------------------*/
#pragma once
#include "GameObject.h"

class Application;
class Resource;

class Camera : public GameObject
{
public:
	Camera();
	~Camera() {};
	void Init()override;
	void Uninit()override{}
	void Update()override;
	void Draw()override;
private:
	D3DXVECTOR3 m_Target;
	Application& m_App;
	Resource& m_Mgr;
	float x, y;
};
