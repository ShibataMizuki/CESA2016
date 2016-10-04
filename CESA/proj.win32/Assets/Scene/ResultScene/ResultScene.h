#pragma once

#include<cocos2d.h>

class ResultScene :public cocos2d::Layer
{
	/*==============================
	Layer�I�[�o�[���C�h
	===============================*/
public:
	CREATE_FUNC(ResultScene);
	static cocos2d::Scene* createScene();
	bool init()override;
	void update(float dt)override;

	/*==============================
	���x��
	===============================*/
private:
	cocos2d::Label* m_pScoreLabel;
	cocos2d::Label* m_pShootDownLabel;
	cocos2d::Label* m_pTextLabel;

	/*==============================
	���Ԃ̊Ǘ�
	===============================*/
private:
	float m_procTime;
	
	/*==============================
	�V�[���ړ��p
	===============================*/
private:
	bool m_isSceneMoving;
};