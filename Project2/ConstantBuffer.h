/*--------------------------------------------------------------

	[ConstantBuffer.h]
	Author : �o���đ�

	�萔�o�b�t�@�̊Ǘ�

---------------------------------------------------------------*/
#pragma once
#include "Resource.h"

class ConstantBuffer
{
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
public:
	enum EBuffer : int32_t
	{
		CONSTANT_WORLDBUFFER, 


	};
	ConstantBuffer();
	~ConstantBuffer();

	void SetWorldViewProjection2D();
	void SetWorldMatrix(D3DXMATRIX * WorldMatrix);
	void SetViewMatrix(D3DXMATRIX * ViewMatrix);
	void SetProjectionMatrix(D3DXMATRIX * ProjectionMatrix);
	void SetMaterial(Resource::Material Material);
	void SetLight(Resource::Light Light);
	void SetCameraPosition(D3DXVECTOR3 CameraPosition);
	void SetParameter(D3DXVECTOR4 Parameter);

private:
	ComPtr<ID3D11Buffer> m_Buffer;
};

