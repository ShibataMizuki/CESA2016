#include "ScoreItem.h"
#include"inc/GameObjects.h"
#include"Utils/Utils.h"
USING_NS_CC;
USING_UTIL;

bool ScoreItem::init()
{
	if (!Node::init())return false;

	m_scoreToHave = 0;

	this->scheduleUpdate();
	this->initMove();

	return true;
}

void ScoreItem::update(float dt)
{
	this->executeMove(dt);
	GameObject::update(dt);
}

void ScoreItem::setScoreToHave(int score)
{
	m_scoreToHave = score;
}

int ScoreItem::getScoreToHave() const
{
	return m_scoreToHave;
}

void ScoreItem::setSprite(cocos2d::Sprite * sprite)
{
	m_pSprite = sprite;
	this->addChild(m_pSprite);
}

cocos2d::Sprite * ScoreItem::getSprite() const
{
	return m_pSprite;
}

void ScoreItem::initMove()
{
	m_procTime = 0.f;
	m_speed = random(100.f, 500.f);
	m_firstDir = convertToDirection(convertToRadian(random(0, 360)));
}

void ScoreItem::executeMove(float dt)
{
	if (m_procTime > 0.5f)
	{
		auto player = GameObjectManager::getInstance()->getPlayerPlane();
		if (!player)return;
		Vec2 dir = player->getPosition() - this->getPosition();
		dir.normalize();
		this->setPosition(this->getPosition() + dir*dt*1500.f);
	}
	else
	{
		this->setPosition(this->getPosition() + m_firstDir*dt*m_speed);
	}
	m_procTime += dt;
}