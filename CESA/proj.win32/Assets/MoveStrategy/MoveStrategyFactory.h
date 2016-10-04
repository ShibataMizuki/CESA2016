#pragma once

#include<cocos2d.h>
#include<memory>
#include"GameObject/GameObject.h"
#include"MoveStrategy.h"

class MoveStrategyFactory
{
public:
	static std::shared_ptr<MoveStrategy> createMoveLinear(
		GameObject* pTargetObject, float moveSpeed, const cocos2d::Vec2& moveDir);
	
	static std::shared_ptr<MoveStrategy> createMoveHoming(
		GameObject* pTargetObject, GameObject* pHomingTarget, 
		float homingInsensity, float moveSpeed, float angle);
	
	static std::shared_ptr<MoveStrategy> createMoveWithKeyboard(
		GameObject* pTargetObject, float moveSpeed);
};