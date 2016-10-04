#include "EnemyBullet.h"

USING_NS_CC;

bool EnemyBullet::init()
{
	if (!GameObject::init())return false;
	m_pSprite = Sprite::create("bullet.png");
	addChild(m_pSprite);
	m_pSprite->setColor(Color3B::RED);
	return true;
}

void EnemyBullet::update(float dt)
{
	GameObject::update(dt);
}

void EnemyBullet::setSprite(cocos2d::Sprite * pSprite)
{
	m_pSprite = pSprite;
}

cocos2d::Sprite * EnemyBullet::getSprite() const
{
	return m_pSprite;
}
