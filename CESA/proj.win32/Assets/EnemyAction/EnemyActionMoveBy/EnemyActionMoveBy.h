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
	//! @brief ����������
	void init()override;
	//! @brief �X�V����
	bool update(float dt)override;

};