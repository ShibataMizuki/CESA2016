#include "EnemyActionMoveBy.h"
#include"GameObject/EnemyPlane/EnemyPlane.h"
USING_NS_CC;

EnemyActionMoveBy::EnemyActionMoveBy(EnemyPlane * pTarget, float duration, const cocos2d::Vec2 & pos) :
	EnemyAction(pTarget, duration), m_pos(pos)
{
}

void EnemyActionMoveBy::init()
{
	m_dir = (m_pTargetEnemy->getPosition() + m_pos) - m_pTargetEnemy->getPosition();
	m_dir.normalize();
	m_speed = ((m_pTargetEnemy->getPosition() + m_pos) - m_pTargetEnemy->getPosition()).getLength() / m_duration;
}

bool EnemyActionMoveBy::update(float dt)
{
	m_pTargetEnemy->setPosition(m_pTargetEnemy->getPosition() + m_dir*dt*m_speed);
	return isFinished(dt);
}
