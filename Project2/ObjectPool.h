/*-----------------------------------------------------------

	[ObjectPool.h]
	Author : �o���đ�

	[����]
	�A�Z�b�g�̃��[�h�A�A�����[�h�A�Ǘ����s��
	�X�^�e�B�b�N�ɂ���Ȃ�A�֐������ŗǂ��ˁH

------------------------------------------------------------*/
#pragma once
#include "DirectXGraphics.h"
#include "PrefabsShader.h"
#include "PrefabsTexture.h"

namespace ObjectPool
{
	// �������̊m��
	void Init();
}

// �e�N�X�`����Getter / Setter
ID3D11ShaderResourceView* GetTexture(int32_t Id);
void SetTexture(DirectXGraphics& dx, int slot, int32_t Id); // slot = �ݒ肷��X���b�g�AID = �i�[ID

// ���_�V�F�[�_�[
void SetVertexShader(DirectXGraphics& dx, int32_t Id); 
void SetInputLayout(DirectXGraphics& dx, int32_t Id);
// �s�N�Z���V�F�[�_�[
void SetPixelShader(DirectXGraphics& dx, int32_t Id);
// �W�I���g���V�F�[�_�[
void SetGeometryShader(DirectXGraphics& dx, int32_t Id);
// �R���s���[�g�V�F�[�_�[
void SetComputeShader(DirectXGraphics& dx, int32_t Id);