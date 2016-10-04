#pragma once

#include"GameObject/GameObject.h"

class EnemyBullet :public GameObject
{
	/*==============================
	GameObject�I�[�o�[���C�h
	===============================*/
public:
	CREATE_FUNC(EnemyBullet);
	bool init()override;
	void update(float dt)override;

	/*==============================
	�X�v���C�g�Ǘ�
	===============================*/
private:
	cocos2d::Sprite* m_pSprite;
public:
	//! @brief �X�v���C�g���Z�b�g
	void setSprite(cocos2d::Sprite* pSprite);
	//! @brief �X�v���C�g���擾
	cocos2d::Sprite* getSprite()const;
};