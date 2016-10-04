#pragma once

#include"GameObject/GameObject.h"

class PlayerBullet :public GameObject
{
	/*==============================
	GameObject�I�[�o�[���C�h
	===============================*/
public:
	CREATE_FUNC(PlayerBullet);
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

	/*==============================
	�^����_���[�W
	===============================*/
private:
	float m_power;
public:
	//! @brief �p���[���Z�b�g����
	void setPower(float power);
	//! @brief �p���[���擾����
	float getPower()const;
};