/*-------------------------------------------------------------

	[Math.h]
	Author : 出合翔太

	エフェクトの動きを計算

--------------------------------------------------------------*/
#pragma once
#include <random>
#include "DirectXGraphics.h"
#include <math.h>

class Math
{

};

/*
		/// 誤差が出ない
		// 中心座標に角度と長さを使用した円の位置を加算する
				// 度数法の角度を弧度法に変換
		float radius = enemy.m_Angle * 3.14f / 180.0f;
		// 三角関数を使用し、円の位置を割り出す。
		float add_x = cos(radius) * enemy.m_Length;
		float add_y = sin(radius) * enemy.m_Length;
		// 結果ででた位置を中心位置に加算し、それを描画位置とする
		enemy.m_PosX = enemy.m_CenterX + add_x;
		enemy.m_PosY = enemy.m_CenterY + add_y;
		
		// 角度を変える
		enemy.m_Angle += 10.0f;
		
		DrawCircle(enemy.m_PosX, enemy.m_PosY, enemy.m_Radius, GetColor(255, 255, 255));


		/// 誤差が出る
		// ベクトルを割り出して今の座標に加算する
		enemy.m_PosX += cos(enemy.m_Angle * 3.14f / 180.0f) * enemy.m_Speed;
		enemy.m_PosY += sin(enemy.m_Angle * 3.14f / 180.0f) * enemy.m_Speed;
		// 向きを変える
		enemy.m_Angle += 10.0f;

		DrawCircle(enemy.m_PosX, enemy.m_PosY, enemy.m_Radius, GetColor(255, 255, 255));

*/