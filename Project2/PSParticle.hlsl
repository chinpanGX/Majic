
#include "CommonParticle.hlsli"

float4 main(GSOutputParticle psIn) : SV_Target
{
    return float4(psIn.Color.rgb, UniParticleSpriteTex.Sample(UniSamplerLinearWrap, psIn.TexCoord).a);
}
