/*-------------------------------------------------------------
	
	[BlendMode.h]
	Author : 出合翔太

	ブレンドモードの設定

--------------------------------------------------------------*/
#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <wrl.h>

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
	BlendMode();
	BlendMode(ID3D11Device* dev, size_t Mode);
	~BlendMode();
	ID3D11BlendState * Get() const;
private:
	Microsoft::WRL::ComPtr<ID3D11BlendState> m_BlendState;
};

