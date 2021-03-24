/*-------------------------------------------------------------

	[Shader.h]
	Author : �o���đ�

	�V�F�[�_�[�̊Ǘ�

--------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"
#include <string>

namespace 
{
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
	// ���_�V�F�[�_�[
	class VertexShader final
	{
	public:
		VertexShader();
		~VertexShader();
		void Load(DirectXGraphics & dx, std::string FileName);
		ComPtr<ID3D11VertexShader> GetVertexShader() const;
		ComPtr<ID3D11InputLayout> GetInputLayout() const;
	private:
		// ����
		void CreateVertexShader(DirectXGraphics & dx, ID3D11VertexShader ** Shader, ID3D11InputLayout ** InputLayout, std::string FileName);

		ComPtr<ID3D11VertexShader> m_VertexShader;
		ComPtr<ID3D11InputLayout> m_InputLayout;
	};

	// �s�N�Z���V�F�[�_�[
	class PixelShader final
	{
	public:
		PixelShader();
		~PixelShader();
		void Load(DirectXGraphics & dx, std::string FileName);
		ComPtr<ID3D11PixelShader> GetPixelShader() const;
	private:
		// ����
		void CreatePixelShader(DirectXGraphics& dx, ID3D11PixelShader** Shader, std::string FileName);

		ComPtr<ID3D11PixelShader> m_PixelShader;
	};

	// �R���s���[�g�V�F�[�_�[
	class ComputeShader final
	{
	public:
		ComputeShader();
		~ComputeShader();
		void Load(DirectXGraphics& dx, std::string FileName);
		ComPtr<ID3D11ComputeShader> GetComputeShader() const;
	private:
		void Create(DirectXGraphics& dx, ID3D11ComputeShader** Shader, std::string FileName);
		ComPtr<ID3D11ComputeShader> m_Computeshader;
	};
};

