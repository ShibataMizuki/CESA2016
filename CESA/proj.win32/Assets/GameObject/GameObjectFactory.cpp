#include "GameObjectFactory.h"
#include"inc/GameObjects.h"

#include"CollisionSystem/CSBody/CSBody.h"

USING_NS_CC;

EnemyPlane * GameObjectFactory::createEnemy(cocos2d::Sprite * pSprite, std::shared_ptr<CSBody> pBody, cocos2d::Vec2 position,float life, int scoreToHave)
{
	auto enemy = EnemyPlane::create();
	enemy->setSprite(pSprite);
	enemy->setBody(pBody);
	enemy->setPosition(position);
	enemy->setLife(life);
	enemy->setScoreToHave(scoreToHave);
	return enemy;
}

EnemyBullet * GameObjectFactory::createEnemyBullet(cocos2d::Sprite * pSprite, std::shared_ptr<CSBody> pBody, cocos2d::Vec2 position)
{
	auto bullet = EnemyBullet::create();
	bullet->setSprite(pSprite);
	bullet->setBody(pBody);
	bullet->setPosition(position);
	return bullet;
}
