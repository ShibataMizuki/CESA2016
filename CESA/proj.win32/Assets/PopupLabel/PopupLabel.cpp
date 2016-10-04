#include "PopupLabel.h"

USING_NS_CC;

cocos2d::Label * createPopupLabel(cocos2d::Label * pLabel)
{
	auto move = MoveBy::create(1.0f, Vec2(0.f, 100.f));
	auto fade = FadeOut::create(1.0f);
	auto spawn = Spawn::create(move, fade, nullptr);
	auto call = CallFunc::create([&]() {});
	auto sequence = Sequence::create(spawn, call, nullptr);

	pLabel->runAction(sequence);

	return pLabel;
}
