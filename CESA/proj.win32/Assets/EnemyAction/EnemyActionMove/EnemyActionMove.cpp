#include "EnemyActionMove.h"
#include"GameObject/EnemyPlane/EnemyPlane.h"
USING_NS_CC;

EnemyActionMove::EnemyActionMove(EnemyPlane * pTarget, const cocos2d::Vec2 & pos, float duration):
	EnemyAction(pTarget,duration),m_pos(pos)
{
	m_speed = (m_pos - m_pTargetEnemy->getPosition()).getLength() / m_duration;
}

bool EnemyActionMove::update(float dt)
{
	Vec2 dir = m_pos - m_pTargetEnemy->getPosition();
	dir.normalize();

	m_pTargetEnemy->setPosition(m_pTargetEnemy->getPosition() + dir*dt*m_speed);

	return this->isFinished(dt);
}
