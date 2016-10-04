#include "WorldManager.h"
#include"CollisionSystem/CSShape/CSShape.h"
#include"CollisionSystem/CSBody/CSBody.h"
#include"CollisionSystem/CSShape/CSCircle/CSCircle.h"
using namespace std;

WorldManager* WorldManager::m_pInstance = nullptr;



WorldManager * WorldManager::getInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new WorldManager();
		m_pInstance->createWorld();
	}
	return m_pInstance;
}

void WorldManager::release()
{
	delete m_pInstance;
}

void WorldManager::createWorld()
{
	m_pWorld = make_shared<CSWorld>();
}

const std::shared_ptr<CSWorld>& WorldManager::getWorld() const
{
	return m_pWorld;
}

void WorldManager::setDrawNode(cocos2d::Layer * pLayer)
{
	m_pDrawNode = cocos2d::DrawNode::create();
	pLayer->addChild(m_pDrawNode,10);
}

void WorldManager::debugDraw()
{
	m_pDrawNode->clear();
	auto& bodyList = m_pWorld->getBodyList();
	for (auto& body : bodyList)
	{
		for (auto& shape : body->getShapeList())
		{
			auto circle = dynamic_cast<CSCircle*>(shape.get());
			if (circle != nullptr)
			{
				auto vec = cocos2d::Vec2(body->getPosition().x, body->getPosition().y);

				cocos2d::Color4F color = cocos2d::Color4F::RED;
				color.a = 128.f;

				m_pDrawNode->drawDot(vec, circle->getRadius(),color);
			}
		}
	}
}
