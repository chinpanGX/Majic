/*----------------------------------------------------------

	[Loader.h]
	読み込みに関するラッパー
	Author : 出合翔太

------------------------------------------------------------*/
#pragma once
#include "Resource.h"

namespace Loader
{
	// テクスチャを管理
	class Texture
	{
	private:
		ID3D11ShaderResourceView* m_Texture = NULL;
	public:
		void Load(Resource& dx, std::string FileName); // ロード
		void Unload();
		ID3D11ShaderResourceView* GetTexture()const; // セット
	};

	// 頂点シェーダー
	class VertexShader
	{
	private:
		ID3D11VertexShader* m_VertexShader = nullptr;
		ID3D11InputLayout*	m_InputLayout = nullptr;
		// 生成
		void CreateVertexShader(Resource & dx, ID3D11VertexShader ** VertexShader, ID3D11InputLayout ** InputLayout, std::string FileName);
	public:
		void Load(Resource & dx, std::string VertexShader_FileName);
		void Unload();
		ID3D11VertexShader* GetVertexShader()const;
		ID3D11InputLayout* GetInputLayout()const;
	};

	// ピクセルシェーダー
	class PixelShader
	{
	private:
		ID3D11PixelShader*	m_PixelShader = NULL;
		// 生成
		void CreatePixelShader(Resource& dx, ID3D11PixelShader** PixelShader, std::string FileName);
	public:
		void Load(Resource & dx, std::string PixelShader_FileName);
		void Unload();
		ID3D11PixelShader* GetPixelShader()const;
	};
}
