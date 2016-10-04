#include "EnemyAI.h"

EnemyAI::EnemyAI(EnemyPlane * pTarget) :
	m_pTargetEnemy(pTarget)
{
}

EnemyAI::~EnemyAI()
{
}

void EnemyAI::setTargetEnemy(EnemyPlane * pTarget)
{
	m_pTargetEnemy = pTarget;
}

EnemyPlane * EnemyAI::getTargetEnemy() const
{
	return m_pTargetEnemy;
}
