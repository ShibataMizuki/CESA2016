#include "EnemyActionMoveTo.h"
#include"GameObject/EnemyPlane/EnemyPlane.h"

USING_NS_CC;

EnemyActionMoveTo::EnemyActionMoveTo(EnemyPlane * pTarget,float duration, const cocos2d::Vec2 & pos) :
	EnemyAction(pTarget, duration), m_pos(pos)
{
}

void EnemyActionMoveTo::init()
{
	m_speed = (m_pos - m_pTargetEnemy->getPosition()).getLength() / m_duration;
	m_dir = m_pos - m_pTargetEnemy->getPosition();
	m_dir.normalize();
}

bool EnemyActionMoveTo::update(float dt)
{
	m_pTargetEnemy->setPosition(m_pTargetEnemy->getPosition() + m_dir*dt*m_speed);
	return this->isFinished(dt);
}
