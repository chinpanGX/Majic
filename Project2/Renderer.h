/*-------------------------------------------------------------
	
	[Renderer.h]
	Author : �o���đ�

	[����]
	Renderer�N���X : 2D�̕`��Ɋւ��鏈�����܂Ƃ߂�

--------------------------------------------------------------*/
#pragma once
#include "Resource.h"

class Renderer
{
public:
	Renderer() : m_Dx(Resource::GetInstance()), m_VertexBuffer(nullptr), m_Alpha(1.0f) {};
	~Renderer() {};
	void Init();
	// ���O�Ƀ|���S��������Ă���
	void Init(D3DXVECTOR2 drawPosition, D3DXVECTOR2 drawSize, D3DXVECTOR2 texUpLeft, D3DXVECTOR2 texDownRight, D3DXCOLOR color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)); 

	void Uninit() {};
	void Update() {};
	void Draw(ID3D11ShaderResourceView* texture, D3DXVECTOR2 drawPosition, D3DXVECTOR2 drawSize, D3DXVECTOR2 texUpLeft, D3DXVECTOR2 texDownRight, D3DXCOLOR color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	void Draw(ID3D11ShaderResourceView* texture);
	void SetAlpha(float alpha) {};
private:
	Resource& m_Dx;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_VertexBuffer;
	float m_Alpha;
};

