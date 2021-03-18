/*-------------------------------------------------------------

	[EmitterManager.h]
	Author : 出合翔太

	エミッターを管理

--------------------------------------------------------------*/
#pragma once
#include "DirectX11.h"

class EmitterManager
{
};

// SRVとUAVで構造化バッファを作成するためのヘルパー関数
template<typename T>
HRESULT CreateStructuedBuffer(UINT NumElements, ID3D11Buffer** ppBufer, ID3D11ShaderResourceView** ppSRV, ID3D11UnorderedAccessView** ppUAV, const T* pInitData = nullptr)
{
	auto r = Re

	HRESULT hr = S_OK;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.ByteWidth = NumElements * sizeof(T);
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.BindFlags = D3D11_BIND_UNORDERED_ACCESS | D3D11_BIND_SHADER_RESOURCE;
	bd.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
	bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
	bd.StructureByteStride = sizeof(T);

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = pInitData;

}