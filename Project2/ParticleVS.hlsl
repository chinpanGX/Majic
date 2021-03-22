/*-----------------------------------------------------
	
	[ParaticleVS.h]
	Author : 出合翔太

	VS：パーティクル
------------------------------------------------------*/
#include "Common.hlsl"
#include "ParticlePS.hlsl"

struct VsInParticle
{
	float4 Position : POSITION;
	float2 TexCoord : TEXCOORD0;
	uint InstanceID : SV_InstanceID;
};

// 座標
StructuredBuffer<float3> Position : register(t2);

void main(in VsInParticle In, out  PsInParticle Out)
{
    matrix wvp;
    wvp = mul(World, View);
    wvp = mul(wvp, Projection);
    
	In.Position.xyz += Position[In.InstanceID];

	Out.Postion = mul(In.Position, wvp);
	Out.WorldPosition = mul(In.Position, World);
	Out.TexCoord = In.TexCoord;
}