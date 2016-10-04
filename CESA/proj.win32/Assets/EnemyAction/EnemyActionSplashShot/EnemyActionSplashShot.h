#pragma once

#include"EnemyAction/EnemyAction.h"

class EnemyActionSplashShot :public EnemyAction
{
private:
	float m_timer;
	//射撃間隔
	float m_shotInterval;
	//バラける広さ
	float m_wide;
	//弾の速さ
	float m_bulletSpeed;
	int m_beatIndex;
public:
	EnemyActionSplashShot(EnemyPlane* pTarget, float duration, float shotIntervel, float wide, float bulletSpeed);

	//! @brief 初期化オーバーライド
	void init()override;
	//! @brief 更新オーバーライド
	bool update(float dt)override;
	//! @brief 拍子番号のセット
	void setBeatIndex(int index);
};