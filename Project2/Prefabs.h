/*-----------------------------------------------------------

	[Prefabs.h]
	Author : �o���đ�

	[����]
	�e�N�X�`���A�V�F�[�_�[�̃��[�h�A�A�����[�h

------------------------------------------------------------*/
#pragma once
#include "Loader.h"
#include <memory>

class PrefabsBase
{
protected:
	int32_t m_Size; // �v���n�u�̐�

public:
	virtual void Load(DirectX11::Manager& dx) = 0;
	virtual void Unload() = 0;
};

namespace Prefabs
{
	// Texture�̃v���n�u
	class Texture : public PrefabsBase
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
		Texture() { m_Size = ID::MAX; }
		void Load(DirectX11::Manager& dx)override;
		void Unload()override;
		ID3D11ShaderResourceView* GetTexture(int32_t Id);
	private:
		std::unique_ptr<Loader::Texture[]> m_Texture;
	};

	// ���_�V�F�[�_�[
	class VertexShader : public PrefabsBase
	{
	public:
		enum ID : int32_t
		{
			DEFAULT,
			MAPPING,
			MAX
		};
		VertexShader() { m_Size = ID::MAX; }
		void Load(DirectX11::Manager& dx)override;
		void Unload()override;
		ID3D11VertexShader* GetVertexShader(int32_t Id);
		ID3D11InputLayout* GetInputLayout(int32_t Id);
	private:
		std::unique_ptr<Loader::VertexShader[]> m_VertexShader;
	};

	// �s�N�Z���V�F�[�_�[
	class PixelShader : public PrefabsBase
	{
	public:
		enum ID : int32_t
		{
			DEFAULT,
			MAPPING,
			MAX
		};
		PixelShader() { m_Size = ID::MAX; }
		void Load(DirectX11::Manager& dx)override;
		void Unload()override;
		ID3D11PixelShader* GetPixelShader(int32_t Id);
	private:
		std::unique_ptr<Loader::PixelShader[]> m_PixelShader;
	};
}

