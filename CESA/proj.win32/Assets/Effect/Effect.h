#pragma once

#include"cocos2d.h"

class Effect :public cocos2d::Node
{
public:
	Effect() = default;
	virtual ~Effect() = default;

	CREATE_FUNC(Effect);
};