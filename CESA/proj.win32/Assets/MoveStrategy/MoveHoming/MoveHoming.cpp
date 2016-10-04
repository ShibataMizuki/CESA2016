#include "MoveHoming.h"
#include"GameObjectManager/GameObjectManager.h"
#include"GameObject/GameObject.h"
USING_NS_CC;

MoveHoming::MoveHoming(GameObject * pTargetObject, GameObject * pHomingTarget, float homingInsensity, float moveSpeed,float angle) :
	MoveStrategy(pTargetObject),
	m_pHomingTarget(pHomingTarget),
	m_homingGraduality(homingInsensity),
	m_moveSpeed(moveSpeed),
	m_homingTargetArriveFlag(true)
{
	m_oldDir = Vec2(cosf(angle), sinf(angle));
	m_oldDir.normalize();
}

void MoveHoming::setHomingTarget(GameObject * pHomingTarget)
{
	m_pHomingTarget = pHomingTarget;
}

void MoveHoming::setHomingInsensity(float homingInsensity)
{
	m_homingGraduality = homingInsensity;
}

void MoveHoming::setMoveSpeed(float moveSpeed)
{
	m_moveSpeed = moveSpeed;
}

GameObject * MoveHoming::getHomingTarget() const
{
	return this->m_pHomingTarget;
}

float MoveHoming::getHomingInsensity() const
{
	return this->m_homingGraduality;
}

float MoveHoming::getMoveSpeed() const
{
	return m_moveSpeed;
}

void MoveHoming::update(float dt)
{
	//�����m�F
	if (m_homingTargetArriveFlag)
	{
		m_homingTargetArriveFlag = GameObjectManager::getInstance()->isArrive(m_pHomingTarget);
	}

	//�ړ�����
	if (m_homingTargetArriveFlag)
	{
		Vec2 targetPos = m_pHomingTarget->getPosition();
		//�ڕW�ւ̕���
		Vec2 targetDir = targetPos - m_pTargetObject->getPosition();
		targetDir.normalize();

		//���̕���
		Vec2 nextDir = targetDir /m_homingGraduality + m_oldDir;
		nextDir.normalize();

		//�ړ�
		m_pTargetObject->setPosition(m_pTargetObject->getPosition()
			+ nextDir*m_moveSpeed*dt);
		m_oldDir = nextDir;
	}
	else
	{
		m_pTargetObject->setPosition(m_pTargetObject->getPosition()
			+ m_oldDir*m_moveSpeed*dt);
	}
}
