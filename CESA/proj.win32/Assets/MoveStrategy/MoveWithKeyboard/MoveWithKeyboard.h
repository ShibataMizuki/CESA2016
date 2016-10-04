#pragma once

#include<cocos2d.h>
#include"MoveStrategy/MoveStrategy.h"

class MoveWithKeyboard :public MoveStrategy
{
private:
	//移動速度
	float m_moveSpeed;

	//キーフラグ
	bool m_pressWFlag;
	bool m_pressAFlag;
	bool m_pressSFlag;
	bool m_pressDFlag;

	//イベントリスナー
	cocos2d::EventListenerKeyboard* m_pListenerKeyboard;

public:
	/*==============================
	ctor
	===============================*/
	MoveWithKeyboard(GameObject* pTargetObject, float moveSpeed);

	/*==============================
	~ctor
	===============================*/
	~MoveWithKeyboard();

	/*==============================
	method
	===============================*/
	void update(float delta)override;
};