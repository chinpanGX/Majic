/*-------------------------------------------------------------

	[Field.h]
	Author : èoçá„ƒëæ

--------------------------------------------------------------*/
#pragma once
#include "GameObject.h"
#include "Polygon.h"

class Field : public GameObject
{
public:
	Field();
	~Field() {}
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

private:
	void Create(class Resource::Vertex Vertex[4]);

	class DirectXGraphics& m_Dx;
	std::unique_ptr<Polygon3D> m_Polygon;
};

