/*-----------------------------------------------------------

	[Prefabs.h]
	Author : 出合翔太

	[説明]
	テクスチャ、シェーダーのロード、アンロード

------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"

namespace Shader
{
	class VertexShader;
	class PixelShader;
	class GeometryShader;
	class ComputeShader;
}

namespace Prefabs
{
	// 頂点シェーダー
	class VertexShader final
	{
	public:
		enum ID : int32_t
		{
			DEFAULT,
			MAPPING,
			MAX
		};
		VertexShader();
		VertexShader(DirectXGraphics& dx);
		~VertexShader();
		ID3D11VertexShader* GetVertexShader(int32_t Id);
		ID3D11InputLayout* GetInputLayout(int32_t Id);
	private:
		static const int32_t m_Size = ID::MAX;
		std::array<std::unique_ptr<Shader::VertexShader>, m_Size> m_VertexShader;
	};

	// ピクセルシェーダー
	class PixelShader final
	{
	public:
		enum ID : int32_t
		{
			DEFAULT,
			MAPPING,
			MAX
		};
		PixelShader();
		PixelShader(DirectXGraphics& dx);
		~PixelShader();
		ID3D11PixelShader* GetPixelShader(int32_t Id);
	private:
		static const int32_t m_Size = ID::MAX;
		std::array<std::unique_ptr<Shader::PixelShader>, m_Size> m_PixelShader;
	};

	class GeometryShader final
	{
	public:
		// ジオメトリシェーダー
		GeometryShader();
		GeometryShader(DirectXGraphics& dx);
		~GeometryShader();
		ID3D11GeometryShader* GetGeometryShader();
	private:
		std::unique_ptr<Shader::GeometryShader> m_GeometryShader;
	};

	// コンピュートシェーダー
	class ComputeShader final
	{
	public:
		ComputeShader();
		ComputeShader(DirectXGraphics& dx);
		~ComputeShader();
		ID3D11ComputeShader* GetComputeShader();
	private:
		std::unique_ptr<Shader::ComputeShader> m_ComputeShader;
	};
}
