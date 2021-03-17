/*-------------------------------------------------------------

	[Camera.cpp]
	Author : èoçá„ƒëæ

--------------------------------------------------------------*/
#include "Camera.h"
#include "Application.h"
#include "Resource.h"

Camera::Camera() : m_App(Application::GetInstance()), m_Mgr(Resource::GetInstance())
{

}

void Camera::Init()
{
	m_Position = D3DXVECTOR3(0.0f, 3.0f, -5.0f);
	m_Target = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	x = (float)m_App.GetWindowSize().cx;
	y = (float)m_App.GetWindowSize().cy;
}

void Camera::Update()
{
}

void Camera::Draw()
{
	D3DXMATRIX view;
	D3DXMatrixLookAtLH(&view, &m_Position, &m_Target, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	m_Mgr.SetProjectionMatrix(&view);

	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(&proj, 1.0f, x / y, 1.0f, 1000.0f);
	m_Mgr.SetProjectionMatrix(&proj);
	m_Mgr.SetCameraPosition(m_Position);
}
