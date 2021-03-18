#include "Renderer.h"
#include "ObjectPool.h"

void Renderer::Init()
{
	CreateVertex();
}

void Renderer::Init(ID3D11ShaderResourceView * texture, D3DXVECTOR2 drawPosition, D3DXVECTOR2 drawSize, D3DXVECTOR2 texUpLeft, D3DXVECTOR2 texDownRight, D3DXCOLOR color, int32_t Id_1, int32_t Id_2)
{
	CreateVertex();
	DynamicChangeBuffer(drawPosition, drawSize, texUpLeft, texDownRight);

	//マテリアル設定
	Resource::Material material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = color;
	m_Dx.SetMaterial(material);

	// シェーダーの設定
	SetShader(Id_1, Id_2);

	//マトリクス設定
	m_Dx.SetWorldViewProjection2D();

	//頂点バッファ設定
	UINT stride = sizeof(Resource::Vertex);
	UINT offset = 0;
	m_Dx.GetDeviceContext()->IASetVertexBuffers(0, 1, m_VertexBuffer.GetAddressOf(), &stride, &offset);

	//テクスチャ設定
	m_Dx.GetDeviceContext()->PSSetShaderResources(0, 1, &texture);

	//プリミティブトポロジ設定
	m_Dx.GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
}

void Renderer::Draw(ID3D11ShaderResourceView * texture, D3DXVECTOR2 drawPosition, D3DXVECTOR2 drawSize, D3DXVECTOR2 texUpLeft, D3DXVECTOR2 texDownRight, D3DXCOLOR color, int32_t Id_1, int32_t Id_2)
{
	//ライト無効
	Resource::Light light;
	light.Enable = false;
	m_Dx.SetLight(light);

	DynamicChangeBuffer(drawPosition, drawSize, texUpLeft, texDownRight);

	// シェーダーの設定
	SetShader(Id_1, Id_2);

	//マトリクス設定
	m_Dx.SetWorldViewProjection2D();

	//頂点バッファ設定
	UINT stride = sizeof(Resource::Vertex);
	UINT offset = 0;
	m_Dx.GetDeviceContext()->IASetVertexBuffers(0, 1, m_VertexBuffer.GetAddressOf(), &stride, &offset);

	//マテリアル設定
	Resource::Material material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = color;
	m_Dx.SetMaterial(material);

	//テクスチャ設定
	m_Dx.GetDeviceContext()->PSSetShaderResources(0, 1, &texture);

	//プリミティブトポロジ設定
	m_Dx.GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//ポリゴン描画
	m_Dx.GetDeviceContext()->Draw(4, 0);

	//変更後は戻しておく
	m_Alpha = 1.0f;
}

void Renderer::Draw()
{
	//ライト無効
	Resource::Light light;
	light.Enable = false;
	m_Dx.SetLight(light);

	//ポリゴン描画
	m_Dx.GetDeviceContext()->Draw(4, 0);

	//変更後は戻しておく
	m_Alpha = 1.0f;
}

void Renderer::CreateVertex()
{
	Resource::Vertex vertex[4];
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


	//頂点バッファ生成
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(Resource::Vertex) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;

	m_Dx.GetDevice()->CreateBuffer(&bd, &sd, m_VertexBuffer.GetAddressOf());
}

void Renderer::DynamicChangeBuffer(D3DXVECTOR2 drawPosition, D3DXVECTOR2 drawSize, D3DXVECTOR2 texUpLeft, D3DXVECTOR2 texDownRight)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	m_Dx.GetDeviceContext()->Map(m_VertexBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	Resource::Vertex* vertex = (Resource::Vertex*)msr.pData;

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

	m_Dx.GetDeviceContext()->Unmap(m_VertexBuffer.Get(), 0);
}

void Renderer::SetShader(int32_t Id_1, int32_t Id_2)
{
	// シェーダーの設定
	ObjectPool::SetInputLayout(m_Dx, Id_1);
	ObjectPool::SetVertexShader(m_Dx, Id_1);
	ObjectPool::SetPixelShader(m_Dx, Id_2);
}
