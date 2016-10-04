#include "PlayerBullet.h"
#include"Effect/EffectCircleSplash.h"
USING_NS_CC;

bool PlayerBullet::init()
{
	if (!GameObject::init())return false;

	return true;
}

void PlayerBullet::update(float dt)
{
	GameObject::update(dt);
}

void PlayerBullet::setPower(float damage)
{
	m_power = damage;
}

float PlayerBullet::getPower() const
{
	return m_power;
}

void PlayerBullet::setSprite(cocos2d::Sprite * pSprite)
{
	m_pSprite = pSprite;
	addChild(pSprite);
}

cocos2d::Sprite * PlayerBullet::getSprite() const
{
	return m_pSprite;
}
