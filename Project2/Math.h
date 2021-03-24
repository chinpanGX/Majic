/*-------------------------------------------------------------

	[Math.h]
	Author : �o���đ�

--------------------------------------------------------------*/
#pragma once
#include <random>
#include "DirectXGraphics.h"
#include <math.h>

namespace Math 
{
	// �G�C���A�X
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
	
	// �V�t�g���Z������A�����n�Ɉˑ����Ȃ��悤��uint�ōs���BHLSL�Ƃ̌݊����̂���`�ɂ���
	using uint = uint32_t;
	using uint4 = DirectX::XMUINT4;

	// Xorshift�V�t�g�ŗ����𐶐�����N���X�@XOR�ƃr�b�g�V�t�g�����ō���
	class XorShift128 final
	{
	public:
		static const int IntMax = 0x7FFFFFFF;
		static const uint UintMax = 0xFFFFFFFFU;
		static const uint MaxVal = 10000; // �Ƃ肠�����ݒ�

		static uint4 CreateRamdomNumber(uint4 random);

		static uint GetRamdomComponentUI(uint4 random);
		
		// 0.0�`1.0�͈̔͂̎�������
		static float GetRamdomComponentUF(uint4 random);

		// -1.0�`+1.0�͈̔͂̎�������
		static float GetRamdomComponentSF(uint4 random);

		// 1�v�f�𕄍��Ȃ�32bit�����Ƃ����Ƃ��A�ő吔��UINT32_MAX�ɂȂ�B
		// �������������߁A�Z�������̗������u0.0�`1.0�v�͈̔͂̎��������ɕϊ�����Ƃ��͏����Ȑ��ŏ�]�����߂�
		static uint4 CreateInitNumber(uint seed);
	};
};

/*
		/// �덷���o�Ȃ�
		// ���S���W�Ɋp�x�ƒ������g�p�����~�̈ʒu�����Z����
				// �x���@�̊p�x���ʓx�@�ɕϊ�
		float radius = enemy.m_Angle * 3.14f / 180.0f;
		// �O�p�֐����g�p���A�~�̈ʒu������o���B
		float add_x = cos(radius) * enemy.m_Length;
		float add_y = sin(radius) * enemy.m_Length;
		// ���ʂłł��ʒu�𒆐S�ʒu�ɉ��Z���A�����`��ʒu�Ƃ���
		enemy.m_PosX = enemy.m_CenterX + add_x;
		enemy.m_PosY = enemy.m_CenterY + add_y;
		
		// �p�x��ς���
		enemy.m_Angle += 10.0f;
		
		DrawCircle(enemy.m_PosX, enemy.m_PosY, enemy.m_Radius, GetColor(255, 255, 255));


		/// �덷���o��
		// �x�N�g��������o���č��̍��W�ɉ��Z����
		enemy.m_PosX += cos(enemy.m_Angle * 3.14f / 180.0f) * enemy.m_Speed;
		enemy.m_PosY += sin(enemy.m_Angle * 3.14f / 180.0f) * enemy.m_Speed;
		// ������ς���
		enemy.m_Angle += 10.0f;

		DrawCircle(enemy.m_PosX, enemy.m_PosY, enemy.m_Radius, GetColor(255, 255, 255));

*/