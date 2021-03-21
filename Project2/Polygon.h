/*-------------------------------------------------------------

	[Polygon.h]
	Author : èoçá„ƒëæ

--------------------------------------------------------------*/
#pragma once
#include <wrl.h>
#include "DirectXGraphics.h"

class Polygon3D
{
public:
	Polygon3D(DirectXGraphics& dx, Resource::Vertex Vertex[4]);
	~Polygon3D() { }
	void DrawPolygon(DirectXGraphics& dx, D3DXVECTOR3 Position, D3DXVECTOR3 Rotation, D3DXVECTOR3 Scale);
private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_VertexBuffer;
};


