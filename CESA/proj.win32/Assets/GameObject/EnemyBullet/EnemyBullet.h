#pragma once

#include"GameObject/GameObject.h"

class EnemyBullet :public GameObject
{
	/*==============================
	GameObjectオーバーライド
	===============================*/
public:
	CREATE_FUNC(EnemyBullet);
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
};