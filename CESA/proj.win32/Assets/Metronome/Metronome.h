#pragma once

#include"cocos2d.h"
#include"ADX2Rapper/ADX2Rapper.h"

class Metronome :public cocos2d::Node
{
private:
	cocos2d::Sprite* m_spr;
	ADX2Player* m_adx2Player;
	float m_bpm;
	// ””
	float m_beatNum;

public:
	Metronome(ADX2Player* adx2Player,float bpm,float beatNum);
	~Metronome() = default;

	static Metronome* create(ADX2Player* adx2Player,float bpm,float beatNum)
	{
		Metronome *pRet = new(std::nothrow) Metronome(adx2Player, bpm, beatNum);
		if (pRet && pRet->init())
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = nullptr;
			return nullptr;
		}
	}

	bool init()override;

	void update(float dt)override;
};