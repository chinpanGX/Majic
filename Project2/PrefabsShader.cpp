/*-----------------------------------------------------------

	[Prefabs.cpp]
	Author : 出合翔太

------------------------------------------------------------*/
#include "Shader.h"
#include "PrefabsShader.h"
#include <io.h>

Prefabs::VertexShader::VertexShader(){}
Prefabs::VertexShader::~VertexShader() {}
Prefabs::VertexShader::VertexShader(DirectXGraphics & dx)
{
	for (int32_t i = 0; i < m_Size; i++)
	{
		m_VertexShader[i] = std::make_unique<Shader::VertexShader>();
	}
	m_VertexShader[0]->Load(dx, "Asset/Shader/vertexShader.cso");
	m_VertexShader[1]->Load(dx, "Asset/Shader/MappingVS.cso");
}
ID3D11VertexShader * Prefabs::VertexShader::GetVertexShader(int32_t Id)
{
	return m_VertexShader[Id]->GetVertexShader().Get();
}

ID3D11InputLayout * Prefabs::VertexShader::GetInputLayout(int32_t Id)
{
	return m_VertexShader[Id]->GetInputLayout().Get();
}

Prefabs::PixelShader::PixelShader() {}
Prefabs::PixelShader::~PixelShader() {}
Prefabs::PixelShader::PixelShader(DirectXGraphics & dx)
{
	for (int32_t i = 0; i < m_Size; i++)
	{
		m_PixelShader[i] = std::make_unique<Shader::PixelShader>();
	}
	m_PixelShader[0]->Load(dx, "Asset/Shader/pixelShader.cso");
	m_PixelShader[1]->Load(dx, "Asset/Shader/MappingPS.cso");
}

ID3D11PixelShader * Prefabs::PixelShader::GetPixelShader(int32_t Id)
{
	return m_PixelShader[Id]->GetPixelShader().Get();
}

// ジオメトリシェーダー
Prefabs::GeometryShader::GeometryShader(){}
Prefabs::GeometryShader::~GeometryShader(){}
Prefabs::GeometryShader::GeometryShader(DirectXGraphics & dx)
{
	m_GeometryShader->Load(dx, "Asset/Shader/GSParticle.cso");
}

ID3D11GeometryShader* Prefabs::GeometryShader::GetGeometryShader()
{
	return m_GeometryShader->GetGeometryShader().Get();
}

//　コンピュートシェーダー
Prefabs::ComputeShader::ComputeShader(){}
Prefabs::ComputeShader::~ComputeShader(){}
Prefabs::ComputeShader::ComputeShader(DirectXGraphics& dx)
{
	m_ComputeShader->Load(dx, "Asset/Shader/CSParticle.cso");
}

ID3D11ComputeShader* Prefabs::ComputeShader::GetComputeShader()
{
	return m_ComputeShader->GetComputeShader().Get();
}