/*-----------------------------------------------------------
	
	[ComputeEffect.h]
	Author : �o���đ�

	GPU�p�[�e�B�N���̃e�X�g

------------------------------------------------------------*/
#pragma once
#include "GameObject.h"

class ComputeEffect : public GameObject
{
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
private:
	std::array<std::unique_ptr<class ParticleCompute>, 512> m_Particle;

	Microsoft::WRL::ComPtr<ID3D11Buffer> m_VertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_ParticleBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_ResultBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_PositionBuffer;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_ParticleSRV;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_PositionSRV;
	Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> m_ResultUAV;
};

