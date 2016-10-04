#pragma once

#include"EnemyAction/EnemyAction.h"

class EnemyActionSplashShot :public EnemyAction
{
private:
	float m_timer;
	//�ˌ��Ԋu
	float m_shotInterval;
	//�o������L��
	float m_wide;
	//�e�̑���
	float m_bulletSpeed;
	int m_beatIndex;
public:
	EnemyActionSplashShot(EnemyPlane* pTarget, float duration, float shotIntervel, float wide, float bulletSpeed);

	//! @brief �������I�[�o�[���C�h
	void init()override;
	//! @brief �X�V�I�[�o�[���C�h
	bool update(float dt)override;
	//! @brief ���q�ԍ��̃Z�b�g
	void setBeatIndex(int index);
};