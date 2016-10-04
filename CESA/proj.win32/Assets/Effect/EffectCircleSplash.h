#pragma once

#include"Effect.h"
USING_NS_CC;

class EffectCircleSplash :public Effect
{
private:


public:

	CREATE_FUNC(EffectCircleSplash);

	bool init()override
	{
		if (!Effect::init())return false;

		auto circle = Sprite::create("ring.png");
		circle->setTag(0);
		addChild(circle);

		circle->setScale(0.0f);
		auto spawn = Spawn::create(EaseQuinticActionOut::create(
			ScaleTo::create(0.4f, 3.0f)),
			FadeOut::create(0.4f),
			nullptr);

		auto callFunc = CallFunc::create([&]()
		{
			removeFromParent();
		});

		auto seque = Sequence::create(spawn, callFunc, nullptr);
		circle->runAction(seque);

		return true;
	}

};