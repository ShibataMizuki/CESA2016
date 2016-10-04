#include "MoveStrategy.h"
#include"GameObject/GameObject.h"

MoveStrategy::MoveStrategy(GameObject * pTargetObject) :
	m_pTargetObject(pTargetObject)
{
}

MoveStrategy::~MoveStrategy()
{
}

void MoveStrategy::setTargetObject(GameObject * pTargetObject)
{
	m_pTargetObject = pTargetObject;
}

GameObject * MoveStrategy::getTargetObject() const
{
	return m_pTargetObject;
}
