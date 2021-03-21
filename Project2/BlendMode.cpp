/*-------------------------------------------------------------

	[BlendMode.cpp]
	Author : 出合翔太

	ブレンドモードの設定

--------------------------------------------------------------*/
#include "BlendMode.h"
#include "Utility.h"

BlendMode::BlendMode() = default;

BlendMode::BlendMode(ID3D11Device* dev, size_t Mode) : m_BlendState(nullptr)
{
	HRESULT hr = S_OK;
	D3D11_BLEND_DESC Desc;
	ZeroMemory(&Desc, sizeof(Desc));
	Desc.AlphaToCoverageEnable = FALSE;
	Desc.IndependentBlendEnable = FALSE;
	Desc.RenderTarget[0].BlendEnable = TRUE;
	
	switch (Mode)
	{
	case BlendMode::BLEND_MODE_NORMAL:
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		break;
	case BlendMode::BLEND_MODE_ADDITION:
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
		break;
	case BlendMode::BLEND_MODE_ADDITIONALPHA:
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
		break;
	case BlendMode::BLEND_MODE_SUBTRACTION:
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_ZERO;
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		break;
	case BlendMode::BLEND_MODE_SCREEN:
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_INV_DEST_COLOR;
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
		break;
	case BlendMode::BLEND_MODE_NONE:
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_ZERO;
		break;
	}
	Desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	Desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	Desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	Desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	Desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	hr = dev->CreateBlendState(&Desc, m_BlendState.GetAddressOf());
	ThrowIfFailed(hr, "CreateBlendState　失敗");
}

BlendMode::~BlendMode()
{
}

ID3D11BlendState * BlendMode::Get()const
{
	return m_BlendState.Get(); 
}

