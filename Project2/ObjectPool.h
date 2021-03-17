/*-----------------------------------------------------------

	[ObjectPool.h]
	Author : �o���đ�

	[����]
	�A�Z�b�g�̃��[�h�A�A�����[�h�A�Ǘ����s��


------------------------------------------------------------*/
#pragma once
#include "Prefabs.h"

// �I�u�W�F�N�g�v�[��
class ObjectPool
{
public:
	static void Init();
	static void Uninit();
	static void Update(DirectX11::Manager& dx, int32_t Id, const char* AnimationName1, const char* AnimationName2, float BlendRate, int Frame);
	static void Draw(DirectX11::Manager& dx, int32_t Id);
	
	// �e�N�X�`����Getter / Setter
	static ID3D11ShaderResourceView* GetTexture(int32_t Id);
	static void SetTexture(DirectX11::Manager& dx, int slot, int32_t Id); // slot = �ݒ肷��X���b�g�AID = �i�[ID

	// �V�F�[�_�[�̐ݒ�
	static void SetVertexShader(DirectX11::Manager& dx, int32_t Id);
	static void SetInputLayout(DirectX11::Manager& dx, int32_t Id);
	static void SetPixelShader(DirectX11::Manager& dx, int32_t Id);
private:
	static std::unique_ptr<Prefabs::Texture> m_Texture;
	static std::unique_ptr<Prefabs::VertexShader> m_VertexShader;
	static std::unique_ptr<Prefabs::PixelShader> m_PixelShader;
};

