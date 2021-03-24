/*--------------------------------------

    [VSParticle.hlsl]
    Author : 出合翔太
    
    GPUパーティクル
---------------------------------------*/
#include "CommonParticle.hlsli"
#include "Common.hlsli"

VSOutputParticle main(VSInputParticle invert)
{
    VSOutputParticle outVert;
    outVert.Position = mul(float4(invert.Position, 1),View);
    outVert.Position /= outVert.Position.w;
    outVert.Angle = invert.Angle;
    outVert.Size = invert.Size;
	//outVert.Color = float4(0.9, 0.1, 0.2, 1);
    outVert.Color = float4(1.0, 0.9, 0.0, 1);
	//outVert.Color = float4(1.0, 1.0, 0.0, 1);

    return outVert;

}