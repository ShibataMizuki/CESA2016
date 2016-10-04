#pragma once

#include<cocos2d.h>
#include<memory>

class EnemyAI;
class EnemyPlane;

class EnemyAIFactory
{
public:
	/*
	ˆÚ“®->’âŽ~->UŒ‚(1”­)->ˆÚ“®
	*/
	static std::shared_ptr<EnemyAI> createPtn1(EnemyPlane* pTarget, const cocos2d::Vec2 & startPos, const cocos2d::Vec2 & attackPos,
		const cocos2d::Vec2 & endPos, float duration1, float duration2, float duration3);
};