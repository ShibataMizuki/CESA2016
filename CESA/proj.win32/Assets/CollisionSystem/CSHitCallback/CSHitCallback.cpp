#include "CSHitCallback.h"

CSHitCallback::CSHitCallback(int collisionGroupA, int collisionGroupB) :
	m_collisionGroupA(collisionGroupA), m_collisionGroupB(collisionGroupB)
{
}

void CSHitCallback::setCollisionGroupA(int group)
{
	m_collisionGroupA = group;
}

void CSHitCallback::setCollisionGroupB(int group)
{
	m_collisionGroupB = group;
}

int CSHitCallback::getCollisionGroupA() const
{
	return m_collisionGroupA;
}

int CSHitCallback::getCollisionGroupB() const
{
	return m_collisionGroupB;
}

std::shared_ptr<CSHitCallback> CSHitCallback::createShared(int collisionGroupA, int collisionGroupB)
{
	return std::make_shared<CSHitCallback>(collisionGroupA, collisionGroupB);
}
