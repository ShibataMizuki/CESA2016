#include "EnemyAction.h"
#include"GameObject/EnemyPlane/EnemyPlane.h"


EnemyAction::EnemyAction(EnemyPlane * pTarget, float duration):
	m_pTargetEnemy(pTarget),
	m_procTime(0.f), m_duration(duration)
{
}

EnemyAction::~EnemyAction()
{
}

bool EnemyAction::isFinished(float dt)
{
	m_procTime += dt;
	return m_procTime >= m_duration ? true : false;
}
