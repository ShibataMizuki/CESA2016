#pragma once

#include<memory>
#include<cocos2d.h>
#include"EnemyAction.h"

#define _ENM_ACT std::shared_ptr<EnemyAction>

//! @brief EnemyActionのシンプルファクトリ
class EnemyActionFactory
{
public:
	//! @brief 絶対座標への直線移動アクション
	static _ENM_ACT createEnemyActionMoveTo(EnemyPlane* pTarget, float duration, const cocos2d::Vec2& pos);
	//! @brief 相対座標への直線移動アクション
	static _ENM_ACT createEnemyActionMoveBy(EnemyPlane* pTarget, float duration, const cocos2d::Vec2& pos);
	//! @brief 狙い撃ち弾発射アクション
	static _ENM_ACT createEnemyActionSnipeShot(EnemyPlane * pTarget, float duration, int beatIndex, float bulletSpeed);
	//! @brief ばらまき弾発射アクション
	static _ENM_ACT createEnemyActionSplashShot(EnemyPlane* pTarget, float duration, int beatIndex, float wide, float bulletSpeed);
};