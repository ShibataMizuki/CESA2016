#pragma once
#include<cocos2d.h>

class VirtualPad :public cocos2d::Node
{
	/*==============================
	cocos2d-xオーバーライド
	===============================*/
public:
	CREATE_FUNC(VirtualPad);
	bool init()override;
	void update(float dt)override;

	/*==============================
	画像管理
	===============================*/
private:
	cocos2d::Sprite* m_pSprite;
public:
	void setSprite(cocos2d::Sprite* pSprite);
	cocos2d::Sprite* getSprite()const;

	/*==============================
	マウス処理
	===============================*/
private:
	bool m_isMove;
	cocos2d::Vec2 m_moveDir;
	float m_distance;
	bool onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoving(float dt);
};