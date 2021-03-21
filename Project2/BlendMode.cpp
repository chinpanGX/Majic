/*-------------------------------------------------------------

	[BlendMode.cpp]
	Author : 出合翔太

	ブレンドモードの設定

--------------------------------------------------------------*/
#include "BlendMode.h"
#include "Utility.h"

BlendMode::BlendMode()
{
}

BlendMode::BlendMode(ID3D11Device* dev, size_t Mode) : m_BlendState(nullptr)
{
	HRESULT hr = S_OK;
	D3D11_BLEND_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.AlphaToCoverageEnable = false;
	bd.IndependentBlendEnable = false;
	bd.RenderTarget[0].BlendEnable = true;

	switch (Mode)
	{
	case BlendMode::BLEND_MODE_NORMAL:
		SetBlend(bd, D3D11_BLEND_SRC_ALPHA, D3D11_BLEND_INV_SRC_ALPHA);
		break;
	case BlendMode::BLEND_MODE_ADDITION:
		SetBlend(bd, D3D11_BLEND_ONE, D3D11_BLEND_ONE);
		break;
	case BlendMode::BLEND_MODE_ADDITIONALPHA:
		SetBlend(bd, D3D11_BLEND_SRC_ALPHA, D3D11_BLEND_ONE);
		break;
	case BlendMode::BLEND_MODE_SUBTRACTION:
		SetBlend(bd, D3D11_BLEND_ZERO, D3D11_BLEND_INV_SRC_ALPHA);
		break;
	case BlendMode::BLEND_MODE_SCREEN:
		SetBlend(bd, D3D11_BLEND_INV_DEST_COLOR, D3D11_BLEND_ONE);
		break;
	case BlendMode::BLEND_MODE_NONE:
	default:
		SetBlend(bd, D3D11_BLEND_ONE, D3D11_BLEND_ZERO);
		break;
	}
	bd.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	bd.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	bd.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	bd.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	dev->CreateBlendState(&bd, m_BlendState.GetAddressOf());
	ThrowIfFailed(hr, "CreateBlendState　失敗");
}

BlendMode::~BlendMode()
{
}

ID3D11BlendState * BlendMode::Get()const
{
	return m_BlendState.Get(); 
}

void BlendMode::SetBlend(D3D11_BLEND_DESC Desc, D3D11_BLEND Src, D3D11_BLEND Dest)
{
	Desc.RenderTarget[0].SrcBlend = Src;
	Desc.RenderTarget[0].DestBlend = Dest;
}

