#include "MoveLinear.h"
#include"GameObject/GameObject.h"

MoveLinear::MoveLinear(GameObject * pTargetObject, float moveSpeed, const cocos2d::Vec2 & moveDir) :
	MoveStrategy(pTargetObject),
	m_moveSpeed(moveSpeed),
	m_moveDir(moveDir)
{
}

void MoveLinear::setMoveSpeed(float moveSpeed)
{
	m_moveSpeed = moveSpeed;
}

void MoveLinear::setMoveDirection(cocos2d::Vec2 moveDir)
{
	m_moveDir = moveDir;
}

float MoveLinear::getMoveSpeed() const
{
	return m_moveSpeed;
}

const cocos2d::Vec2 & MoveLinear::getMoveDirection() const
{
	return m_moveDir;
}

void MoveLinear::update(float dt)
{
	m_pTargetObject->setPosition(m_pTargetObject->getPosition() + m_moveDir*m_moveSpeed*dt);
}
