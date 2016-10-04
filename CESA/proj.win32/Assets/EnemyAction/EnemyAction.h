#pragma once

class EnemyPlane;

class EnemyAction
{
protected:
	EnemyPlane* m_pTargetEnemy;
	float m_procTime;
	float m_duration;
	//! @brief アクションが終了したかどうか
	bool isFinished(float dt);

public:
	EnemyAction(EnemyPlane* pTarget, float duration);

	virtual ~EnemyAction();
	
	//! @brief 初期化処理
	virtual void init() = 0;
	//! @brief 更新処理
	virtual bool update(float dt) = 0;
};