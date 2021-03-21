/*-------------------------------------------------------------
	
	[BlendMode.h]
	Author : 出合翔太

	ブレンドモードの設定

--------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"

class BlendMode
{
public:
	enum EMode
	{
		BLEND_MODE_NONE,
		BLEND_MODE_NORMAL,
		BLEND_MODE_ADDITION,
		BLEND_MODE_ADDITIONALPHA,
		BLEND_MODE_SUBTRACTION,
		BLEND_MODE_SCREEN,
		NUM_MAX
	};
	BlendMode() {}
	BlendMode(ID3D11Device* dev, EMode Mode);
	~BlendMode();
	inline ID3D11BlendState* Get()const { return m_BlendState.Get(); }
private:
	//									Src = 合成色(上レイヤー)Dest = 基本色(下レイヤー)
	void SetBlend(D3D11_BLEND_DESC Desc, D3D11_BLEND Src, D3D11_BLEND Dest);

	Microsoft::WRL::ComPtr<ID3D11BlendState> m_BlendState;
};

