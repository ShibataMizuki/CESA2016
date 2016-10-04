#pragma once

#include"GameObject/EnemyPlane/EnemyPlane.h"

class EnemyAI
{
protected:
	EnemyPlane* m_pTargetEnemy;

public:
	/*==============================
	ctor
	===============================*/
	EnemyAI(EnemyPlane* pTarget);
	virtual ~EnemyAI();

	/*==============================
	setter
	===============================*/
	void setTargetEnemy(EnemyPlane* pTarget);

	/*==============================
	getter
	===============================*/
	EnemyPlane* getTargetEnemy()const;

	/*==============================
	method
	===============================*/
	virtual void update(float dt) = 0;
	
};