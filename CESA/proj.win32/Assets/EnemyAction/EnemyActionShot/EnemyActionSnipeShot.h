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
	//! @brief 初期化オーバーライド
	void init()override;
	//! @brief 更新処理オーバーライド
	bool update(float dt)override;
	//! @brief 拍子番号のセット
	void setBeatIndex(int index);
};