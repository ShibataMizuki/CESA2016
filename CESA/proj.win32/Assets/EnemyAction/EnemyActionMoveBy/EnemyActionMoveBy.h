#pragma once

#include<cocos2d.h>
#include"EnemyAction/EnemyAction.h"

class EnemyActionMoveBy :public EnemyAction
{
private:
	cocos2d::Vec2 m_pos;
	float m_speed;
	cocos2d::Vec2 m_dir;

public:
	EnemyActionMoveBy(EnemyPlane* pTarget, float duration,
		const cocos2d::Vec2& pos);
	//! @brief ‰Šú‰»ˆ—
	void init()override;
	//! @brief XVˆ—
	bool update(float dt)override;

};