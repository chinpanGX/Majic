/*--------------------------------------------------------------

	[ConstantBuffer.cpp]
	Author : 出合翔太

	定数バッファの管理

---------------------------------------------------------------*/
#include "ConstantBuffer.h"

ConstantBuffer::ConstantBuffer()
{
}

ConstantBuffer::~ConstantBuffer()
{
}

void ConstantBuffer::SetWorldViewProjection2D()
{
}

void ConstantBuffer::SetWorldMatrix(D3DXMATRIX * WorldMatrix)
{
}

void ConstantBuffer::SetViewMatrix(D3DXMATRIX * ViewMatrix)
{
}

void ConstantBuffer::SetProjectionMatrix(D3DXMATRIX * ProjectionMatrix)
{
}

void ConstantBuffer::SetMaterial(Resource::Material Material)
{
}

void ConstantBuffer::SetLight(Resource::Light Light)
{
}

void ConstantBuffer::SetCameraPosition(D3DXVECTOR3 CameraPosition)
{
}

void ConstantBuffer::SetParameter(D3DXVECTOR4 Parameter)
{
}
