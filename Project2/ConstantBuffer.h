/*--------------------------------------------------------------

	[ConstantBuffer.h]
	Author : 出合翔太

	定数バッファの管理

---------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"
#include <vector>

class ConstantBuffer
{
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
public:
	enum EBuffer : int32_t
	{
		CONSTANT_BUFFER_WORLD,
		CONSTANT_BUFFER_VIEW,
		CONSTANT_BUFFER_PROJECTION,
		CONSTANT_BUFFER_MATERIAL,
		CONSTANT_BUFFER_LIGHT,
		CONSTANT_BUFFER_CAMERA,
		CONSTANT_BUFFER_PARAMETER,
		NUM_MAX
	};
	ConstantBuffer();
	ConstantBuffer(ID3D11Device* Dev, ID3D11DeviceContext* Context);
	~ConstantBuffer();

	ID3D11Buffer* Get(EBuffer Buf) const;
private:
	std::array<ComPtr<ID3D11Buffer>, EBuffer::NUM_MAX> m_Buffer;
};
