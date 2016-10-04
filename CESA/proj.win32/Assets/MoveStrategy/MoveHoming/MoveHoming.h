#pragma once

#include<cocos2d.h>
#include"MoveStrategy/MoveStrategy.h"

class MoveHoming :public MoveStrategy
{
private:
	//ホーミング対象
	GameObject* m_pHomingTarget;
	//ホーミングのゆるやかさ（1で最短距離）
	float m_homingGraduality;
	//移動速度
	float m_moveSpeed;

	//前フレームに向いていた角度
	cocos2d::Vec2 m_oldDir;
	//ホーミング対象が生存しているかどうかのフラグ。生存していればtrue,それ以外ならばfalse
	bool m_homingTargetArriveFlag;

public:
	/*==============================
	ctor
	===============================*/
	
	//angle[radian] : float
	MoveHoming(GameObject* pTargetObject, GameObject* pHomingTarget, float homingInsensity, float moveSpeed,float angle);

	/*==============================
	setter
	===============================*/
	void setHomingTarget(GameObject* pHomingTarget);
	void setHomingInsensity(float homingInsensity);
	void setMoveSpeed(float moveSpeed);

	/*==============================
	getter
	===============================*/
	GameObject* getHomingTarget()const;
	float getHomingInsensity()const;
	float getMoveSpeed()const;

	/*==============================
	method
	===============================*/
	void update(float dt)override;
};