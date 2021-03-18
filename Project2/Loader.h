/*----------------------------------------------------------

	[Loader.h]
	読み込みに関するラッパー
	Author : 出合翔太

------------------------------------------------------------*/
#pragma once
#include "Resource.h"

namespace Loader
{
	template< typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
	// テクスチャを管理
	class Texture
	{
	public:
		Texture(){}
		~Texture(){}
		void Load(Resource& dx, std::string FileName); // ロード
		ComPtr<ID3D11ShaderResourceView> GetTexture()const
		{
			return m_Texture;
		}
	private:
		ComPtr<ID3D11ShaderResourceView> m_Texture = nullptr;
	};

	// 頂点シェーダー
	class VertexShader
	{
	public:
		VertexShader(){}
		~VertexShader(){}
		void Load(Resource & dx, std::string VertexShader_FileName);
		ComPtr<ID3D11VertexShader> GetVertexShader()const
		{
			return m_VertexShader;
		}
		ComPtr<ID3D11InputLayout> GetInputLayout()const
		{
			return m_InputLayout;
		}

	private:
		// 生成
		void CreateVertexShader(Resource & dx, ID3D11VertexShader ** VertexShader, ID3D11InputLayout ** InputLayout, std::string FileName);
		
		ComPtr<ID3D11VertexShader> m_VertexShader = nullptr;
		ComPtr<ID3D11InputLayout> m_InputLayout = nullptr;
	};

	// ピクセルシェーダー
	class PixelShader
	{
	public:
		PixelShader(){}
		~PixelShader(){}
		void Load(Resource & dx, std::string PixelShader_FileName);
		ComPtr<ID3D11PixelShader> GetPixelShader()const
		{
			return m_PixelShader;
		}
	private:
		// 生成
		void CreatePixelShader(Resource& dx, ID3D11PixelShader** PixelShader, std::string FileName);

		ComPtr<ID3D11PixelShader> m_PixelShader = nullptr;
	};
}
