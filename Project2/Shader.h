/*-------------------------------------------------------------

	[Shader.h]
	Author : �o���đ�

	�V�F�[�_�[�̊Ǘ�

--------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"

namespace Shader
{
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;

	// ���_�V�F�[�_�[
	class VertexShader
	{
	public:
		VertexShader() {}
		~VertexShader() {}
		void Load(DirectXGraphics & dx, std::string VertexShader_FileName);
		ComPtr<ID3D11VertexShader> GetVertexShader()const
		{
			return m_VertexShader;
		}
		ComPtr<ID3D11InputLayout> GetInputLayout()const
		{
			return m_InputLayout;
		}

	private:
		// ����
		void CreateVertexShader(DirectXGraphics & dx, ID3D11VertexShader ** VertexShader, ID3D11InputLayout ** InputLayout, std::string FileName);

		ComPtr<ID3D11VertexShader> m_VertexShader = nullptr;
		ComPtr<ID3D11InputLayout> m_InputLayout = nullptr;
	};

	// �s�N�Z���V�F�[�_�[
	class PixelShader
	{
	public:
		PixelShader() {}
		~PixelShader() {}
		void Load(DirectXGraphics & dx, std::string PixelShader_FileName);
		ComPtr<ID3D11PixelShader> GetPixelShader()const
		{
			return m_PixelShader;
		}
	private:
		// ����
		void CreatePixelShader(DirectXGraphics& dx, ID3D11PixelShader** PixelShader, std::string FileName);

		ComPtr<ID3D11PixelShader> m_PixelShader = nullptr;
	};
};

