/*-----------------------------------------------------------

	[ObjectPool.h]
	Author : �o���đ�

	[����]
	�A�Z�b�g�̃��[�h�A�A�����[�h�A�Ǘ����s��

------------------------------------------------------------*/
#pragma once
#include "Prefabs.h"

// �I�u�W�F�N�g�v�[��
class ObjectPool final
{
public:
	~ObjectPool();
	static void Init();
	static void Update(DirectXGraphics& dx, int32_t Id, const char* AnimationName1, const char* AnimationName2, float BlendRate, int Frame);
	static void Draw(DirectXGraphics& dx, int32_t Id);
	
	// �e�N�X�`����Getter / Setter
	static ID3D11ShaderResourceView* GetTexture(int32_t Id);
	static void SetTexture(DirectXGraphics& dx, int slot, int32_t Id); // slot = �ݒ肷��X���b�g�AID = �i�[ID

	// �V�F�[�_�[�̐ݒ�
	static void SetVertexShader(DirectXGraphics& dx, int32_t Id);
	static void SetInputLayout(DirectXGraphics& dx, int32_t Id);
	static void SetPixelShader(DirectXGraphics& dx, int32_t Id);
private:
	static std::unique_ptr<Prefabs::Texture> m_Texture;
	static std::unique_ptr<Prefabs::VertexShader> m_VertexShader;
	static std::unique_ptr<Prefabs::PixelShader> m_PixelShader;
};

