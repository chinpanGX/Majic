
// 定数
#define CS_LOCAL_GROUP_SIZE         (256)
#define CS_PARTICLES_NUM_PER_THREAD  (4)

// コンスタントバッファ関連
cbuffer vcbSceneParam : register(b0)
{
    uint UniSpawnTargetParticleIndex : packoffset(c8.w);
    float3 UniMaxParticleVelocity : packoffset(c9);
    float UniMaxAngularVelocity : packoffset(c9.w); // [Radian]
    uint UniMaxParticleCount : packoffset(c10.x);
    float UniParticleInitSize : packoffset(c10.y);
};

Texture2D UniParticleSpriteTex : register(t0);
SamplerState UniSamplerLinearWrap : register(s0);


// 頂点情報
struct VSInputParticle
{
    float3 Position : POSITION0;
    float3 Velocity : VELOCITY0;
    float Angle : ANGLE0;
    float DeltaAngle : DANGLE0;
    float Size : PSIZE0;
	//uint Life         : LIFE0;
    uint4 RandomSeed : RANDOM0;
};


struct VSOutputParticle
{
    float4 Position : SV_Position;
    float Angle : ANGLE;
    float Size : PSIZE;
    float4 Color : COLOR;
};

struct GSOutputParticle
{
    float4 Position : SV_Position;
    float4 Color : COLOR;
    float2 TexCoord : TEXCOORD;
};
