#pragma once

#include"EnemyAction/EnemyAction.h"

class EnemyActionSnipeShot :public EnemyAction
{
private:
	float m_shotInterval;
	float m_timer;
	float m_bulletSpeed;
	float m_beatIndex;

public:
	EnemyActionSnipeShot(EnemyPlane * pTarget, float duration, float shotInterval,float bulletSpeed);
	//! @brief �������I�[�o�[���C�h
	void init()override;
	//! @brief �X�V�����I�[�o�[���C�h
	bool update(float dt)override;
	//! @brief ���q�ԍ��̃Z�b�g
	void setBeatIndex(int index);
};