#pragma once

#include<cocos2d.h>
#include"GameObject/GameObject.h"
#include"ADX2Rapper/ADX2Rapper.h"

class EnemyPlane;

class PlayerPlane :public GameObject
{
	/*==============================
	GameObject�I�[�o�[���C�h
	===============================*/
public:
	CREATE_FUNC(PlayerPlane);
	bool init()override;
	void update(float dt)override;

	/*==============================
	�R���X�g���N�^
	===============================*/
public:
	PlayerPlane() {}
	~PlayerPlane() {}

	/*==============================
	�摜�Ǘ�
	===============================*/
private:
	cocos2d::Sprite* m_pSprite;
public:
	void setSprite(cocos2d::Sprite* pSprite);
	cocos2d::Sprite* getSprite()const;

	/*==============================
	���C�t�Ǘ�
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
	���C���ˌ�����
	===============================*/
private:
	//�A�ˑ��x(rate/sec)
	static constexpr float m_shotPerSec = 10.0f;
	float m_prevShotDeltaTime;
	void executeShooting(float dt);

	/*==============================
	�z�[�~���O�ˌ�����
	===============================*/
private:
	bool m_homingShotEnable;
	void initHomingShot();
	void shotHomingBullet(EnemyPlane* enemyPlane);
	void executeHomingShot(float dt);

public:
	/*==============================
	���C�t�Ǘ�
	===============================*/
	void takeDamage(int damage);
	void repairDamage(int repairValue);
};