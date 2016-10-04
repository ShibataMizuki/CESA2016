#include "EnemyAIFactory.h"

#include"EnemyAIPtn1/EnemyAIPtn1.h"

std::shared_ptr<EnemyAI> EnemyAIFactory::createPtn1(EnemyPlane * pTarget, const cocos2d::Vec2 & startPos, const cocos2d::Vec2 & attackPos, const cocos2d::Vec2 & endPos, float duration1, float duration2, float duration3)
{
	auto enemyAI = std::make_shared<EnemyAIPtn1>(pTarget, startPos, attackPos, endPos, duration1, duration2, duration3);
	return enemyAI;
}
