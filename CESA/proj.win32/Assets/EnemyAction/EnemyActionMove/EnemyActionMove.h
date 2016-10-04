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
	//! @brief �������I�[�o�[���C�h
	void init()override {}
	//! @brief �X�V�I�[�o�[���C�h
	bool update(float dt)override;
};