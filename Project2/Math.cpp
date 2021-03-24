/*-------------------------------------------------------------

	[Math.cpp]
	Author : o‡ãÄ‘¾

--------------------------------------------------------------*/
#include "Math.h"

Math::uint4 Math::XorShift128::CreateRamdomNumber(uint4 random)
{
	const uint tmp = (random.x ^ (random.x << 11));
	random.x = random.y;
	random.y = random.z;
	random.z = random.w;
	random.w = (random.w = (random.w ^ (random.w >> 19)) ^ (tmp ^ (tmp >> 8)));
	return random;
}

Math::uint Math::XorShift128::GetRamdomComponentUI(uint4 random)
{
	return random.w;
}

float Math::XorShift128::GetRamdomComponentUF(uint4 random)
{
	return float(GetRamdomComponentUI(random) % MaxVal) / float(MaxVal);
}

float Math::XorShift128::GetRamdomComponentSF(uint4 randam)
{
	return 2.0f * GetRamdomComponentUF(randam) - 1.0f;
}

Math::uint4 Math::XorShift128::CreateInitNumber(uint seed)
{
	// ‰Šú’l‚ª0‚Ì‚Æ‚«
	if (seed == 0)
	{
		seed += 11; // ‰ÁZ
	}

	uint4 tmp;
	tmp.w = seed;
	tmp.x = (seed << 16) + (seed >> 16);
	tmp.y = tmp.w + tmp.x;
	tmp.z = tmp.x ^ tmp.y;

	return tmp;
}
