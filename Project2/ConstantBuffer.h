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
		CONSTANT_BUFFER_PROJECTON,
		CONSTANT_BUFFER_MATERIAL,
		CONSTANT_BUFFER_LIGHT,
		CONSTANT_BUFFER_CAMERA,
		CONSTANT_BUFFER_PARAMETER,
		NUM_MAX
	};
	ConstantBuffer(){}
	ConstantBuffer(ID3D11Device* Dev, ID3D11DeviceContext* Context, EBuffer Buffer);
	~ConstantBuffer();

	ID3D11Buffer* Get(EBuffer Buf)
	{
		return m_Buffer[Buf].Get();
	}

private:
	ComPtr<ID3D11Buffer> m_Buffer[EBuffer::NUM_MAX];
	std::vector<ConstantBuffer::EBuffer> m_BufferList;
};

