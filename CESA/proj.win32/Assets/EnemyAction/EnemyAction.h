#pragma once

class EnemyPlane;

class EnemyAction
{
protected:
	EnemyPlane* m_pTargetEnemy;
	float m_procTime;
	float m_duration;
	//! @brief �A�N�V�������I���������ǂ���
	bool isFinished(float dt);

public:
	EnemyAction(EnemyPlane* pTarget, float duration);

	virtual ~EnemyAction();
	
	//! @brief ����������
	virtual void init() = 0;
	//! @brief �X�V����
	virtual bool update(float dt) = 0;
};