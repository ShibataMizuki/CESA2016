#pragma once

#include<cocos2d.h>
#include"MoveStrategy/MoveStrategy.h"

class MoveWithKeyboard :public MoveStrategy
{
private:
	//�ړ����x
	float m_moveSpeed;

	//�L�[�t���O
	bool m_pressWFlag;
	bool m_pressAFlag;
	bool m_pressSFlag;
	bool m_pressDFlag;

	//�C�x���g���X�i�[
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