/*-------------------------------------------------------------

	[Math.h]
	Author : 出合翔太

--------------------------------------------------------------*/
#pragma once
#include <random>
#include "DirectXGraphics.h"
#include <math.h>

namespace Math 
{
	// エイリアス
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
	
	// シフト演算を言語、処理系に依存しないようにuintで行う。HLSLとの互換性のある形にする
	using uint = uint32_t;
	using uint4 = DirectX::XMUINT4;

	// Xorshiftシフトで乱数を生成するクラス　XORとビットシフトだけで高速
	class XorShift128 final
	{
	public:
		static const int IntMax = 0x7FFFFFFF;
		static const uint UintMax = 0xFFFFFFFFU;
		static const uint MaxVal = 10000; // とりあえず設定

		static uint4 CreateRamdomNumber(uint4 random);

		static uint GetRamdomComponentUI(uint4 random);
		
		// 0.0～1.0の範囲の実数乱数
		static float GetRamdomComponentUF(uint4 random);

		// -1.0～+1.0の範囲の実数乱数
		static float GetRamdomComponentSF(uint4 random);

		// 1要素を符号なし32bit整数としたとき、最大数はUINT32_MAXになる。
		// 周期が長いため、短い周期の乱数を「0.0～1.0」の範囲の実数乱数に変換するときは小さな数で剰余を求める
		static uint4 CreateInitNumber(uint seed);
	};
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