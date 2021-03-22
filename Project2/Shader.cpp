/*-------------------------------------------------------------

	[Shader.h]
	Author : 出合翔太

	シェーダーの管理

--------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <string>
#include "Shader.h"
#include "Prefabs.h"

Shader::VertexShader::VertexShader() : m_VertexShader(nullptr), m_InputLayout(nullptr) {}
Shader::VertexShader::~VertexShader() {}

void Shader::VertexShader::Load(DirectXGraphics & dx, std::string VertexShader_FileName)
{
	CreateVertexShader(dx, m_VertexShader.GetAddressOf(), m_InputLayout.GetAddressOf(), VertexShader_FileName);
}

Microsoft::WRL::ComPtr<ID3D11VertexShader> Shader::VertexShader::GetVertexShader() const
{
	return m_VertexShader;
}

Microsoft::WRL::ComPtr<ID3D11InputLayout> Shader::VertexShader::GetInputLayout() const
{
	return m_InputLayout;
}

void Shader::VertexShader::CreateVertexShader(DirectXGraphics & dx, ID3D11VertexShader ** VertexShader, ID3D11InputLayout ** InputLayout, std::string FileName)
{
	auto dev = dx.GetDevice();
	FILE* file;
	long int fsize;
	file = fopen(FileName.c_str(), "rb");
	fsize = _filelength(_fileno(file));
	unsigned char* buffer = new unsigned char[fsize];
	fread(buffer, fsize, 1, file);
	fclose(file);
	dev->CreateVertexShader(buffer, fsize, nullptr, VertexShader);

	// 入力レイアウト生成
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 4 * 3, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 4 * 6, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 4 * 10, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};
	UINT numElements = ARRAYSIZE(layout);
	dev->CreateInputLayout(layout, numElements, buffer, fsize, InputLayout);
	delete[] buffer;
}

Shader::PixelShader::PixelShader() : m_PixelShader(nullptr){}
Shader::PixelShader::~PixelShader(){}

void Shader::PixelShader::Load(DirectXGraphics & dx, std::string PixelShader_FileName)
{
	CreatePixelShader(dx, m_PixelShader.GetAddressOf(), PixelShader_FileName);
}

Microsoft::WRL::ComPtr<ID3D11PixelShader> Shader::PixelShader::GetPixelShader() const
{
	return m_PixelShader;
}

void Shader::PixelShader::CreatePixelShader(DirectXGraphics & dx, ID3D11PixelShader ** PixelShader, std::string FileName)
{
	auto dev = dx.GetDevice();
	FILE* file;
	long int fsize;
	file = fopen(FileName.c_str(), "rb");
	fsize = _filelength(_fileno(file));
	unsigned char* buffer = new unsigned char[fsize];
	fread(buffer, fsize, 1, file);
	fclose(file);
	dev->CreatePixelShader(buffer, fsize, nullptr, PixelShader);
	delete[] buffer;
}

Shader::ComputeShader::ComputeShader() : m_Computeshader(nullptr) {}
Shader::ComputeShader::~ComputeShader(){}

void Shader::ComputeShader::Load(DirectXGraphics & dx, std::string FileName)
{
	Create(dx, m_Computeshader.GetAddressOf(), FileName);
}

Microsoft::WRL::ComPtr<ID3D11ComputeShader> Shader::ComputeShader::GetComputeShader() const
{
	return m_Computeshader;
}

void Shader::ComputeShader::Create(DirectXGraphics & dx, ID3D11ComputeShader ** Shader, std::string FileName)
{
	auto dev = dx.GetDevice();
	FILE* file;
	long int fsize;
	file = fopen(FileName.c_str(), "rb");
	fsize = _filelength(_fileno(file));
	unsigned char* buffer = new unsigned char[fsize];
	fread(buffer, fsize, 1, file);
	fclose(file);
	dev->CreateComputeShader(buffer, fsize, nullptr, Shader);
	delete[] buffer;
}
