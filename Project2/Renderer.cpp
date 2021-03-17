#include "Renderer.h"
#include "ObjectPool.h"

void Renderer::Init()
{
	DirectX11::Vertex vertex[4];
	vertex[0].Position = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(10.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 10.0f);

	vertex[3].Position = D3DXVECTOR3(1.0f, -1.0f, 0.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(10.0f, 10.0f);


	//���_�o�b�t�@����
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(DirectX11::Vertex) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;

	m_Dx.GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);
}

void Renderer::Draw(ID3D11ShaderResourceView * texture, D3DXVECTOR2 drawPosition, D3DXVECTOR2 drawSize, D3DXVECTOR2 texUpLeft, D3DXVECTOR2 texDownRight, D3DXCOLOR color)
{
	//���C�g����
	DirectX11::Light light;
	light.Enable = false;
	m_Dx.SetLight(light);

	D3D11_MAPPED_SUBRESOURCE msr;
	m_Dx.GetDeviceContext()->Map(m_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	DirectX11::Vertex* vertex = (DirectX11::Vertex*)msr.pData;

	vertex[0].Position = D3DXVECTOR3(drawPosition.x - drawSize.x * 0.5f, drawPosition.y - drawSize.y * 0.5f, 0.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = texUpLeft;

	vertex[1].Position = D3DXVECTOR3(drawPosition.x + drawSize.x * 0.5f, drawPosition.y - drawSize.y * 0.5f, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(texDownRight.x, texUpLeft.y);

	vertex[2].Position = D3DXVECTOR3(drawPosition.x - drawSize.x * 0.5f, drawPosition.y + drawSize.y * 0.5f, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(texUpLeft.x, texDownRight.y);

	vertex[3].Position = D3DXVECTOR3(drawPosition.x + drawSize.x * 0.5f, drawPosition.y + drawSize.y * 0.5f, 0.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = texDownRight;

	m_Dx.GetDeviceContext()->Unmap(m_VertexBuffer, 0);

	
	// �V�F�[�_�[�̐ݒ�
	ObjectPool::SetInputLayout(m_Dx, Prefabs::VertexShader::DEFAULT);
	ObjectPool::SetVertexShader(m_Dx, Prefabs::VertexShader::DEFAULT);
	ObjectPool::SetPixelShader(m_Dx, Prefabs::PixelShader::DEFAULT);

	//�}�g���N�X�ݒ�
	m_Dx.SetWorldViewProjection2D();

	//���_�o�b�t�@�ݒ�
	UINT stride = sizeof(DirectX11::Vertex);
	UINT offset = 0;
	m_Dx.GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

	//�}�e���A���ݒ�
	DirectX11::Material material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = color;
	m_Dx.SetMaterial(material);

	//�e�N�X�`���ݒ�
	m_Dx.GetDeviceContext()->PSSetShaderResources(0, 1, &texture);

	//�v���~�e�B�u�g�|���W�ݒ�
	m_Dx.GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//�|���S���`��
	m_Dx.GetDeviceContext()->Draw(4, 0);

	//�ύX��͖߂��Ă���
	m_Alpha = 1.0f;
}