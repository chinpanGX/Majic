/*-------------------------------------------------------------
	
	[Polygon.cpp]
	Author : 出合翔太

--------------------------------------------------------------*/
#include "Resource.h"
#include "Polygon.h"

Polygon3D::Polygon3D(Resource & Res, Resource::Vertex Vertex[4])
{
	// 頂点バッファ生成
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(Resource::Vertex) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = Vertex;

	Res.GetDevice()->CreateBuffer(&bd, &sd, m_VertexBuffer.GetAddressOf());
}

void Polygon3D::DrawPolygon(Resource & Res, D3DXVECTOR3 Position, D3DXVECTOR3 Rotation, D3DXVECTOR3 Scale)
{
	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, Scale.x, Scale.y, Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, Rotation.y, Rotation.x, Rotation.z);
	D3DXMatrixTranslation(&trans, Position.x, Position.y, Position.z);
	world = scale * rot * trans;
	Res.SetWorldMatrix(&world);
	// 頂点バッファ設定
	UINT stride = sizeof(Resource::Vertex);
	UINT offset = 0;
	Res.GetDeviceContext()->IASetVertexBuffers(0, 1, m_VertexBuffer.GetAddressOf(), &stride, &offset);
	// マテリアル設定
	Resource::Material material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	Res.SetMaterial(material);

	// プリミティブトポロジ設定
	Res.GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// ポリゴン描画
	Res.GetDeviceContext()->Draw(4, 0);
}
