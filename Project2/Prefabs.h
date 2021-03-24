/*-----------------------------------------------------------

	[Prefabs.h]
	Author : �o���đ�

	[����]
	�e�N�X�`���A�V�F�[�_�[�̃��[�h�A�A�����[�h

------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"
#include "Shader.h"
#include <array>

class LoadTexture
{
	template< typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
public:
	LoadTexture();
	~LoadTexture();
	inline void Load(DirectXGraphics& dx, std::string FileName) // ���[�h
	{
		D3DX11CreateShaderResourceViewFromFile(dx.GetDevice(), FileName.c_str(), NULL, NULL, m_Texture.GetAddressOf(), NULL);
	}
	ComPtr<ID3D11ShaderResourceView> GetTexture()const
	{
		return m_Texture;
	}
private:
	ComPtr<ID3D11ShaderResourceView> m_Texture = nullptr;
};

namespace Prefabs
{
	// Texture�̃v���n�u
	class Texture
	{
	public:
		enum ID : int32_t
		{
			FADE,
			TATILE_BG,
			GAME_BG,
			FIELD,
			WAFFURU,
			EFFECT,
			MAX
		};
		Texture();
		Texture(DirectXGraphics& dx);
		~Texture();
		ID3D11ShaderResourceView* GetTexture(int32_t Id);
	private:
		static const int32_t m_Size = ID::MAX;
		std::array<std::unique_ptr<LoadTexture>, m_Size> m_Texture;
	};
	
	class Shader
	{

	};

	// ���_�V�F�[�_�[
	class VertexShader
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

	// �s�N�Z���V�F�[�_�[
	class PixelShader
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

	// �R���s���[�g�V�F�[�_�[
	class ComputeShader
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
