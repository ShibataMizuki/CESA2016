#pragma once

#include<cocos2d.h>
#include"GameObject/GameObject.h"
#include"ADX2Rapper/ADX2Rapper.h"

class EnemyPlane;

class PlayerPlane :public GameObject
{
	/*==============================
	GameObjectオーバーライド
	===============================*/
public:
	CREATE_FUNC(PlayerPlane);
	bool init()override;
	void update(float dt)override;

	/*==============================
	コンストラクタ
	===============================*/
public:
	PlayerPlane() {}
	~PlayerPlane() {}

	/*==============================
	画像管理
	===============================*/
private:
	cocos2d::Sprite* m_pSprite;
public:
	void setSprite(cocos2d::Sprite* pSprite);
	cocos2d::Sprite* getSprite()const;

	/*==============================
	ライフ管理
	===============================*/
private:
	static const int LifeMax = 3;
	int m_life;
	cocos2d::Sprite* m_sprLife[LifeMax];
	cocos2d::Sprite* m_sprLifeDamaged[LifeMax];
	void updateLifeSprite();
public:
	int getLife()const;

	/*==============================
	メイン射撃処理
	===============================*/
private:
	//連射速度(rate/sec)
	static constexpr float m_shotPerSec = 10.0f;
	float m_prevShotDeltaTime;
	void executeShooting(float dt);

	/*==============================
	ホーミング射撃処理
	===============================*/
private:
	bool m_homingShotEnable;
	void initHomingShot();
	void shotHomingBullet(EnemyPlane* enemyPlane);
	void executeHomingShot(float dt);

public:
	/*==============================
	ライフ管理
	===============================*/
	void takeDamage(int damage);
	void repairDamage(int repairValue);
};