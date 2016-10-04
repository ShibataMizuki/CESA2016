#pragma once

#include"EnemyAI/EnemyAI.h"

class EnemyAIPtn1 :public EnemyAI
{
private:
	//èÛë‘
	enum class STATE:int
	{
		MOVE1,
		ATTACK,
		MOVE2,
		END
	};

	//èÛë‘èÛãµ
	STATE m_state;

	cocos2d::Vec2 m_startPos;
	cocos2d::Vec2 m_attackPos;
	cocos2d::Vec2 m_endPos;
	float m_duration1;
	float m_duration2;
	float m_duration3;


	cocos2d::Vec2 m_dir1;
	cocos2d::Vec2 m_dir2;
	float m_speed1;
	float m_speed2;
	bool m_flag;

	//åoâﬂéûä‘
	float m_prevShotDeltaTime;

private:
	void Move1(float dt);
	void Attack(float dt);
	void Move2(float dt);
	void End(float dt);

public:
	/*==============================
	ctor
	===============================*/
	EnemyAIPtn1(EnemyPlane* pTarget,const cocos2d::Vec2& startPos, const cocos2d::Vec2& attackPos,
		const cocos2d::Vec2& endPos, float duration1, float duration2, float duration3);

	/*==============================
	method
	===============================*/
	void update(float dt);
};