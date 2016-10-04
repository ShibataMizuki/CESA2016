#pragma once

#include<cocos2d.h>
#include<queue>
#include"CollisionSystem/CSWorld/CSWorld.h"

class EnemyPlane;

class PlayScene :public cocos2d::Layer
{
private:
	enum class NODE_DEPTH :int
	{
		BACK_GROUND = -1,
		GAME_OBJECT = 0,
		UI,
	};

	/*==============================
	敵出現システム
	===============================*/
	std::priority_queue<std::pair<float, EnemyPlane*>,
		std::vector<std::pair<float,EnemyPlane*>>,
		std::greater<std::pair<float,EnemyPlane*>>> m_enemyQueue;
	float m_prevShotDeltaTime;
	void enemyQueueInit();
	void enemyQueueExecute(float dt);

	/*==============================
	リザルト
	===============================*/
private:
	bool m_isFinished;
	float m_finishTimeCnt;
	bool m_sceneMoveFlg;

public:
	void executeFinish(float dt);

	/*==============================
	ラベル
	===============================*/
private:
	cocos2d::Label* m_pLabel;
	bool m_appendFlag;

public:
	/*==============================
	cocos2d-x
	===============================*/
	CREATE_FUNC(PlayScene);
	static cocos2d::Scene* createScene();
	bool init()override;
	void update(float dt)override;

	/*==============================
	ctor
	===============================*/
	PlayScene();

	/*==============================
	setter
	===============================*/

	/*==============================
	getter
	===============================*/

	/*==============================
	method
	===============================*/

};