#include "GameObject.h"
#include"MoveStrategy/MoveStrategy.h"
#include"WorldManager/WorldManager.h"

using namespace std;
/*
void GameObject::setShape(const std::shared_ptr<CollisionShape>& pShape)
{
	m_pShape = pShape;
}

const std::shared_ptr<CollisionShape>& GameObject::getShape() const
{
	return m_pShape;
}
*/

bool GameObject::init()
{
	if (!Node::init())return false;
	scheduleUpdate();
	return true;
}

void GameObject::setBody(const std::shared_ptr<CSBody>& pBody)
{
	m_pBody = pBody;
	pBody->setUserData(this);
	WorldManager::getInstance()->getWorld()->addBody(pBody);
}

const std::shared_ptr<CSBody>& GameObject::getBody() const
{
	return m_pBody;
}

void GameObject::setMoveStrategy(const std::shared_ptr<MoveStrategy>& pMoveStrategy)
{
	m_pMoveStrategy = pMoveStrategy;
}

const std::shared_ptr<MoveStrategy>& GameObject::getMoveStrategy() const
{
	return m_pMoveStrategy;
}

void GameObject::setRemoveFlag(bool flag)
{
	m_removeFlag = flag;
}

bool GameObject::getRemoveFlag() const
{
	return m_removeFlag;
}

void GameObject::update(float dt)
{
	if (m_pMoveStrategy.get() != nullptr)
	{
		m_pMoveStrategy->update(dt);
	}
	if (m_pBody != nullptr)
	{
		m_pBody->setPosition(CSVec2(this->getPosition().x, this->getPosition().y));
	}
}

GameObject::~GameObject()
{
	if (m_pBody != nullptr)
	{
		WorldManager::getInstance()->getWorld()->destroyBody(m_pBody);
	}
}
