/*-------------------------------------------------------------

	[Math.h]
	Author : �o���đ�

	�G�t�F�N�g�̓������v�Z

--------------------------------------------------------------*/
#pragma once
#include <random>
#include "DirectXGraphics.h"
#include <math.h>

class Math
{
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