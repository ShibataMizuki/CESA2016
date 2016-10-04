#pragma once

#include<cocos2d.h>

class GameObject;
class PlayerPlane;
class EnemyPlane;
class EnemyBullet;
class CSBody;

class GameObjectFactory
{
public:
	static EnemyPlane* createEnemy(cocos2d::Sprite* pSprite,std::shared_ptr<CSBody> pBody,cocos2d::Vec2 position,float life,int scoreToHave);
	static EnemyBullet* createEnemyBullet(cocos2d::Sprite* pSprite, std::shared_ptr<CSBody> pBody, cocos2d::Vec2 position);
};