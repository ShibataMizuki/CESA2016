#pragma once

#include<cocos2d.h>

class ResultScene :public cocos2d::Layer
{
	/*==============================
	Layerオーバーライド
	===============================*/
public:
	CREATE_FUNC(ResultScene);
	static cocos2d::Scene* createScene();
	bool init()override;
	void update(float dt)override;

	/*==============================
	ラベル
	===============================*/
private:
	cocos2d::Label* m_pScoreLabel;
	cocos2d::Label* m_pShootDownLabel;
	cocos2d::Label* m_pTextLabel;

	/*==============================
	時間の管理
	===============================*/
private:
	float m_procTime;
	
	/*==============================
	シーン移動用
	===============================*/
private:
	bool m_isSceneMoving;
};