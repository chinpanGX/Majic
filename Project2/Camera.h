/*-------------------------------------------------------------
	
	[Camera.h]
	Author : èoçá„ƒëæ

--------------------------------------------------------------*/
#pragma once
#include "GameObject.h"

class Application;
class DirectX11::Manager;

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
	DirectX11::Manager& m_Mgr;
	float x, y;
};

