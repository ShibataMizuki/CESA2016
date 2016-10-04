#pragma once

#include"../CSShape.h"
#include<memory>

class CSCircle :public CSShape
{
protected:
	//! ‰~‚Ì”¼Œa
	float m_radius;

public:
	/*==============================
	ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	===============================*/
	CSCircle();
	CSCircle(float radius);
	CSCircle(const CSVec2& pos, float radius);

	/*==============================
	‰~‚Ì”¼Œa‚ÌŠÇ—
	===============================*/
	void setRadius(float radius);
	float getRadius()const;

	/*==============================
	shared_ptr¶¬
	===============================*/
	static std::shared_ptr<CSCircle> createShared();
	static std::shared_ptr<CSCircle> createShared(float radius);
	static std::shared_ptr<CSCircle> createShared(const CSVec2& pos, float radius);
};