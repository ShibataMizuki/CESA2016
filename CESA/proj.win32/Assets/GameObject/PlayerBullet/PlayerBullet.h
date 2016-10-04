#pragma once

#include"GameObject/GameObject.h"

class PlayerBullet :public GameObject
{
	/*==============================
	GameObjectオーバーライド
	===============================*/
public:
	CREATE_FUNC(PlayerBullet);
	bool init()override;
	void update(float dt)override;

	/*==============================
	スプライト管理
	===============================*/
private:
	cocos2d::Sprite* m_pSprite;
public:
	//! @brief スプライトをセット
	void setSprite(cocos2d::Sprite* pSprite);
	//! @brief スプライトを取得
	cocos2d::Sprite* getSprite()const;

	/*==============================
	与えるダメージ
	===============================*/
private:
	float m_power;
public:
	//! @brief パワーをセットする
	void setPower(float power);
	//! @brief パワーを取得する
	float getPower()const;
};