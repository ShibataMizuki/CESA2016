#pragma once

#include<memory>
#include<cocos2d.h>
#include"EnemyAction.h"

#define _ENM_ACT std::shared_ptr<EnemyAction>

//! @brief EnemyAction�̃V���v���t�@�N�g��
class EnemyActionFactory
{
public:
	//! @brief ��΍��W�ւ̒����ړ��A�N�V����
	static _ENM_ACT createEnemyActionMoveTo(EnemyPlane* pTarget, float duration, const cocos2d::Vec2& pos);
	//! @brief ���΍��W�ւ̒����ړ��A�N�V����
	static _ENM_ACT createEnemyActionMoveBy(EnemyPlane* pTarget, float duration, const cocos2d::Vec2& pos);
	//! @brief �_�������e���˃A�N�V����
	static _ENM_ACT createEnemyActionSnipeShot(EnemyPlane * pTarget, float duration, int beatIndex, float bulletSpeed);
	//! @brief �΂�܂��e���˃A�N�V����
	static _ENM_ACT createEnemyActionSplashShot(EnemyPlane* pTarget, float duration, int beatIndex, float wide, float bulletSpeed);
};