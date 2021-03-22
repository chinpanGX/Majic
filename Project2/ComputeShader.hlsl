/*----------------------------------------------------

    [ComputeShader]
    Author : 出合翔太

    パーティクルの計算

------------------------------------------------------*/

// パーティクル
struct Particle
{
    float3 pos;
    float3 vel;
    float life;
};

// CSの設定
struct CSInput
{
    uint3 groupThead : SV_GroupThreadID;
    uint3 group : SV_GroupID;
    uint groupIndex : SV_GroupIndex;
    uint3 dispatch : SV_DispatchThreadID;
};

// IN
StructuredBuffer<Particle> InParticle : register(t0);
// OUT
RWStructuredBuffer<Particle> BufferOut : register(u0);

#define size_x 256
#define size_y 1
#define size_z 1

[numthreads(size_x, size_y, size_z)]
void main(const CSInput input)
{
    int index = input.dispatch.x;
    float3 result = InParticle[index].pos + InParticle[index].vel;
    BufferOut[index].pos = result;
    BufferOut[index].life = InParticle[index].life - 1.0f;
    BufferOut[index].vel = InParticle[index].vel;
}