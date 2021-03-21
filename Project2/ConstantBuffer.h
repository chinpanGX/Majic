/*--------------------------------------------------------------

	[ConstantBuffer.h]
	Author : 出合翔太

	定数バッファの管理

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

