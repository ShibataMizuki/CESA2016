#pragma once

#include<cocos2d.h>

class UINode :public cocos2d::Node
{
private:
	cocos2d::Label* m_pScoreLabel;

public:
	/*==============================
	cocos2d-x
	===============================*/
	CREATE_FUNC(UINode);
	bool init()override;
	void update(float dt)override;

};