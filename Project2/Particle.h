/*-------------------------------------------------------------

	[Particle.h]
	Author : 出合翔太

	パーティクルの処理
	エミッターを基準に生成する

--------------------------------------------------------------*/
#pragma once
#include "GameObject.h"
#include "Math.h"

class VertexParticle final
{
public:
	D3DXVECTOR3 Position;
	D3DXVECTOR3 Velocity;
	float Angle;
	float DeltaAngle;
	float Size;
	uint32_t Life;
	DirectX::XMUINT4 RandomSeed;
};

class BufferCommon final
{
public:
	uint32_t UniSpawnTargetParticleIndex;
	D3DXVECTOR3 UniParticleVelocity;
	float UniMaxAngularVelocity; // radian
	uint32_t UniMaxParticleCount;
	float UniParticleInitSize;
	D3DXVECTOR2 Dummy0;
};

class GPUParticle : public GameObject
{
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
public:
	GPUParticle();
	~GPUParticle();
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
private:
	static const uint32_t MaxParticleCount = 10000;
	BufferCommon m_CommonHost;
	//ComPtr<ID3D11VertexShader> m_pVertexShaderParticle1;
	ComPtr<ID3D11VertexShader> m_pVertexShaderParticle2;
	ComPtr<ID3D11VertexShader> m_pVertexShaderParticle2SB;
	ComPtr<ID3D11GeometryShader> m_pGeometryShaderParticle;
	ComPtr<ID3D11PixelShader> m_pPixelShaderParticle;
	ComPtr<ID3D11ComputeShader> m_pComputeShaderParticle;

	//ComPtr<ID3D11InputLayout> m_pVertexInputLayoutParticle1;
	ComPtr<ID3D11InputLayout> m_pVertexInputLayoutParticle2;
	//ComPtr<ID3D11Buffer> m_pVertexBufferParticles1;
	ComPtr<ID3D11Buffer> m_pVertexBufferParticles2;
	ComPtr<ID3D11Buffer> m_pStructBufferParticles2;
	ComPtr<ID3D11UnorderedAccessView> m_pVertexBufferParticles2UAV;
	ComPtr<ID3D11UnorderedAccessView> m_pStructBufferParticles2UAV;
	ComPtr<ID3D11ShaderResourceView> m_pStructBufferParticles2SRV;
	ComPtr<ID3D11Buffer> m_pConstBufferCommon;

	std::vector<VertexParticle> m_ParticleHost;
};
