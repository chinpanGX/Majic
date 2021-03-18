/*-----------------------------------------------------------

	[Loader.cpp]
	Author : 出合翔太

------------------------------------------------------------*/
#include "Loader.h"
#include <io.h>

// ロード
void Loader::Texture::Load(Resource& dx, std::string FileName)
{
	D3DX11CreateShaderResourceViewFromFile(dx.GetDevice(), FileName.c_str(), NULL, NULL, m_Texture.GetAddressOf(), NULL);
}


void Loader::VertexShader::CreateVertexShader(Resource & dx, ID3D11VertexShader ** VertexShader, ID3D11InputLayout ** InputLayout, std::string FileName)
{
	FILE* file;
	long int fsize;
	file = fopen(FileName.c_str(), "rb");
	fsize = _filelength(_fileno(file));
	unsigned char* buffer = new unsigned char[fsize];
	fread(buffer, fsize, 1, file);
	fclose(file);
	dx.GetDevice()->CreateVertexShader(buffer, fsize, NULL, VertexShader);

	// 入力レイアウト生成
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 4 * 3, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 4 * 6, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 4 * 10, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};
	UINT numElements = ARRAYSIZE(layout);
	dx.GetDevice()->CreateInputLayout(layout, numElements, buffer, fsize, InputLayout);
	delete[] buffer;
}

void Loader::VertexShader::Load(Resource & dx, std::string VertexShader_FileName)
{
	CreateVertexShader(dx, m_VertexShader.GetAddressOf(), m_InputLayout.GetAddressOf(), VertexShader_FileName);
}

void Loader::PixelShader::CreatePixelShader(Resource & dx, ID3D11PixelShader ** PixelShader, std::string FileName)
{
	FILE* file;
	long int fsize;
	file = fopen(FileName.c_str(), "rb");
	fsize = _filelength(_fileno(file));
	unsigned char* buffer = new unsigned char[fsize];
	fread(buffer, fsize, 1, file);
	fclose(file);
	dx.GetDevice()->CreatePixelShader(buffer, fsize, NULL, PixelShader);
	delete[] buffer;
}

void Loader::PixelShader::Load(Resource & dx, std::string PixelShader_FileName)
{
	CreatePixelShader(dx, m_PixelShader.GetAddressOf(), PixelShader_FileName);
}
