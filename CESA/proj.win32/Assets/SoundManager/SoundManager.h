#pragma once

#include"ADX2Rapper/ADX2Rapper.h"

class SoundManager
{
	/*==============================
	シングルトン関係
	===============================*/
private:
	static SoundManager* m_pInstance;
	SoundManager() = default;
	~SoundManager() = default;
	SoundManager(SoundManager&) = delete;
	SoundManager(SoundManager&&) = delete;
	SoundManager& operator=(SoundManager&) = delete;
public:
	static SoundManager* getInstance();
	void release();

	/*==============================
	BGMの管理
	===============================*/
private:
	ADX2Player* m_pBackSound;
	float m_backSoundBPM;
	CriSint64 m_beatInterval[4];
	CriSint64 m_timeToPrevBeat[4];
	bool m_beatFlag[4];
public:
	void setBackSound(ADX2Player* pBackSound, float backSoundBPM);
	ADX2Player* getBackSound()const;
	float getBackSoundBPM()const;
	CriSint64 getBeatInterval(int index)const;

	//前の拍子からの時間
	CriSint64 getTimeToPrevBeat(int index)const;

	//次の拍子までの時間
	CriSint64 getTimeToNextBeat(int index)const;
	bool isBeat(int index)const;
	void updateTimeToNextBeat();

public:
};