#include"Utils.h"

cocos2d::Vec2 Util::convertToDirection(float angle)
{
	return cocos2d::Vec2(cosf(angle), sinf(angle));
}
