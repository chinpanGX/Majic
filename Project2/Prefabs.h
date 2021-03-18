/*-----------------------------------------------------------

	[Prefabs.h]
	Author : �o���đ�

	[����]
	�e�N�X�`���A�V�F�[�_�[�̃��[�h�A�A�����[�h

------------------------------------------------------------*/
#pragma once
#include "Resource.h"
#include "Loader.h"
#include <array>

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
		Texture(){}
		Texture(Resource& dx);
		~Texture() {}
		ID3D11ShaderResourceView* GetTexture(int32_t Id);
	private:
		static const int32_t m_Size = ID::MAX;
		std::array<std::unique_ptr<Loader::Texture>, m_Size> m_Texture;
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
		VertexShader(){}
		VertexShader(Resource& dx);
		~VertexShader(){}
		ID3D11VertexShader* GetVertexShader(int32_t Id);
		ID3D11InputLayout* GetInputLayout(int32_t Id);
	private:
		static const int32_t m_Size = ID::MAX;
		std::array<std::unique_ptr<Loader::VertexShader>, m_Size> m_VertexShader;
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
		PixelShader(){}
		PixelShader(Resource& dx);
		~PixelShader() {}
		ID3D11PixelShader* GetPixelShader(int32_t Id);
	private:
		static const int32_t m_Size = ID::MAX;
		std::array<std::unique_ptr<Loader::PixelShader>, m_Size> m_PixelShader;
	};
}

