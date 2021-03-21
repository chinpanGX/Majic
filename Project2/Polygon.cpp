/*-------------------------------------------------------------
	
	[Polygon.cpp]
	Author : �o���đ�

--------------------------------------------------------------*/
#include "DirectXGraphics.h"
#include "Polygon.h"

Polygon3D::Polygon3D(DirectXGraphics & dx, Resource::Vertex Vertex[4])
{
	// ���_�o�b�t�@����
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(Resource::Vertex) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = Vertex;

	dx.GetDevice()->CreateBuffer(&bd, &sd, m_VertexBuffer.GetAddressOf());
}

void Polygon3D::DrawPolygon(DirectXGraphics & dx, D3DXVECTOR3 Position, D3DXVECTOR3 Rotation, D3DXVECTOR3 Scale)
{
	auto& d = dx;
	// �}�g���N�X�ݒ�
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, Scale.x, Scale.y, Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, Rotation.y, Rotation.x, Rotation.z);
	D3DXMatrixTranslation(&trans, Position.x, Position.y, Position.z);
	world = scale * rot * trans;
	d.SetWorldMatrix(&world);
	// ���_�o�b�t�@�ݒ�
	UINT stride = sizeof(Resource::Vertex);
	UINT offset = 0;
	d.GetDeviceContext()->IASetVertexBuffers(0, 1, m_VertexBuffer.GetAddressOf(), &stride, &offset);
	// �}�e���A���ݒ�
	Resource::Material material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	d.SetMaterial(material);

	// �v���~�e�B�u�g�|���W�ݒ�
	d.GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// �|���S���`��
	d.GetDeviceContext()->Draw(4, 0);
}
