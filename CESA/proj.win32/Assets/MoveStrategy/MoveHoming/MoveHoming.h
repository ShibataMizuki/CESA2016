#pragma once

#include<cocos2d.h>
#include"MoveStrategy/MoveStrategy.h"

class MoveHoming :public MoveStrategy
{
private:
	//�z�[�~���O�Ώ�
	GameObject* m_pHomingTarget;
	//�z�[�~���O�̂��₩���i1�ōŒZ�����j
	float m_homingGraduality;
	//�ړ����x
	float m_moveSpeed;

	//�O�t���[���Ɍ����Ă����p�x
	cocos2d::Vec2 m_oldDir;
	//�z�[�~���O�Ώۂ��������Ă��邩�ǂ����̃t���O�B�������Ă����true,����ȊO�Ȃ��false
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