#pragma once

#include<cocos2d.h>

class TitleScene :public cocos2d::Layer
{
private:
public:
	/*==============================
	cocos2d-x
	===============================*/
	CREATE_FUNC(TitleScene);
	static cocos2d::Scene* createScene();
	bool init()override;
	void update(float dt)override;

	bool m_isSceneMoving;
	float m_procTime;

	/*==============================
	ctor
	===============================*/

	/*==============================
	setter
	===============================*/

	/*==============================
	getter
	===============================*/

	/*==============================
	method
	===============================*/

};