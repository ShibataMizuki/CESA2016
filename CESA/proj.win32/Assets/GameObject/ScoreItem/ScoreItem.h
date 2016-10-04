#pragma once

#include<cocos2d.h>
#include"GameObject/GameObject.h"

class ScoreItem :public GameObject
{
	/*==============================
	cocos2d-x�I�[�o�[���C�h
	===============================*/
public:
	CREATE_FUNC(ScoreItem);
	bool init()override;
	void update(float dt)override;

	/*==============================
	�X�R�A�̊Ǘ�
	===============================*/
private:
	int m_scoreToHave;
public:
	void setScoreToHave(int score);
	int getScoreToHave()const;

	/*==============================
	�摜�̊Ǘ�
	===============================*/
private:
	cocos2d::Sprite* m_pSprite;
public:
	void setSprite(cocos2d::Sprite* sprite);
	cocos2d::Sprite* getSprite()const;

	/*==============================
	�ړ�����
	===============================*/
private:
	float m_speed;
	cocos2d::Vec2 m_firstDir;
	float m_procTime;
	void initMove();
	void executeMove(float dt);
};