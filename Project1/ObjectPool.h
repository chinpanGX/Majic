/*-----------------------------------------------------------

	[Engine.h]
	Author : �o���đ�

------------------------------------------------------------*/
#pragma once
#include "Prefabs.h"

// �I�u�W�F�N�g�v�[��
class ObjectPool
{
private:
	static Prefabs::Texture* m_Texture;
	static Prefabs::VertexShader* m_VertexShader;
	static Prefabs::PixelShader* m_PixelShader;
	//static Prefabs::Model* m_Model;
public:
	static void Init();
	static void Uninit();
	static void Update(DirectX11::Manager& dx, unsigned __int32 Id, const char* AnimationName1, const char* AnimationName2, float BlendRate, int Frame);
	static void Draw(DirectX11::Manager& dx, unsigned __int32 Id);
	// �e�N�X�`����Getter / Setter
	static ID3D11ShaderResourceView* GetTexture(unsigned int Id);
	static void SetTexture(DirectX11::Manager& dx, int slot, unsigned int Id); // slot = �ݒ肷��X���b�g�AID = �i�[ID

	// �V�F�[�_�[�̐ݒ�
	static void SetVertexShader(DirectX11::Manager& dx, unsigned int Id);
	static void SetInputLayout(DirectX11::Manager& dx, unsigned int Id);
	static void SetPixelShader(DirectX11::Manager& dx, unsigned int Id);
};

