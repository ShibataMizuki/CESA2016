#include "MoveStrategyFactory.h"
#include"MoveLinear/MoveLinear.h"
#include"MoveHoming/MoveHoming.h"
#include"MoveWithKeyboard/MoveWithKeyboard.h"

std::shared_ptr<MoveStrategy> MoveStrategyFactory::createMoveLinear(GameObject * pTargetObject, float moveSpeed, const cocos2d::Vec2 & moveDir)
{
	return std::make_shared<MoveLinear>(pTargetObject, moveSpeed, moveDir);
}

std::shared_ptr<MoveStrategy> MoveStrategyFactory::createMoveHoming(GameObject * pTargetObject, GameObject * pHomingTarget, float homingInsensity, float moveSpeed, float angle)
{
	return std::make_shared<MoveHoming>(pTargetObject, pHomingTarget, homingInsensity, moveSpeed, angle);
}

std::shared_ptr<MoveStrategy> MoveStrategyFactory::createMoveWithKeyboard(GameObject * pTargetObject, float moveSpeed)
{
	return std::make_shared<MoveWithKeyboard>(pTargetObject, moveSpeed);
}
