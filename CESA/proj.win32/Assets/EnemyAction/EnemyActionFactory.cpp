#include "EnemyActionFactory.h"
#include"EnemyActionMoveBy/EnemyActionMoveBy.h"
#include"EnemyActionMoveTo/EnemyActionMoveTo.h"
#include"EnemyActionShot/EnemyActionSnipeShot.h"
#include"EnemyActionSplashShot/EnemyActionSplashShot.h"

#define _MAKE std::make_shared

_ENM_ACT EnemyActionFactory::createEnemyActionMoveTo(EnemyPlane* pTarget, float duration, const cocos2d::Vec2& pos)
{
	return _MAKE<EnemyActionMoveTo>(pTarget, duration, pos);
}

_ENM_ACT EnemyActionFactory::createEnemyActionMoveBy(EnemyPlane* pTarget, float duration, const cocos2d::Vec2& pos)
{
	return _MAKE<EnemyActionMoveBy>(pTarget, duration, pos);
}

_ENM_ACT EnemyActionFactory::createEnemyActionSnipeShot(EnemyPlane * pTarget, float duration, int beatIndex, float bulletSpeed)
{
	auto enemy= _MAKE<EnemyActionSnipeShot>(pTarget, duration, 0.f, bulletSpeed);
	enemy->setBeatIndex(beatIndex);
	return enemy;
}

_ENM_ACT EnemyActionFactory::createEnemyActionSplashShot(EnemyPlane * pTarget, float duration,int beatIndex, float wide, float bulletSpeed)
{
	auto enemy = _MAKE<EnemyActionSplashShot>(pTarget, duration, 0.f, wide, bulletSpeed);
	enemy->setBeatIndex(beatIndex);
	return enemy;
}
