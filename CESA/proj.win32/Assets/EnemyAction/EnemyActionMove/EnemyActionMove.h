#pragma once

#include<cocos2d.h>
#include"EnemyAction/EnemyAction.h"

class EnemyActionMove :public EnemyAction
{
private:
	cocos2d::Vec2 m_pos;
	float m_speed;

public:
	EnemyActionMove(EnemyPlane* pTarget, const cocos2d::Vec2& pos, float duration);
	//! @brief 初期化オーバーライド
	void init()override {}
	//! @brief 更新オーバーライド
	bool update(float dt)override;
};