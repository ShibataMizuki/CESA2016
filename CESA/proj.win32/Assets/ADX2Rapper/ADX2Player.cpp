#include "ADX2Player.h"



ADX2Player::ADX2Player(CriAtomExAcbHn acbHandle, CriAtomExCueId cueId)
{
	m_playerHandle = criAtomExPlayer_Create(NULL, NULL, 0);
	criAtomExPlayer_SetCueId(m_playerHandle, acbHandle, cueId);
}


ADX2Player::~ADX2Player()
{
}


// 再生の開始
CriAtomExPlaybackId ADX2Player::start()
{
	return criAtomExPlayer_Start(m_playerHandle);
}


// 再生準備
CriAtomExPlaybackId ADX2Player::prepare()
{
	return criAtomExPlayer_Prepare(m_playerHandle);
}

// 再生停止
void ADX2Player::stop()
{
	criAtomExPlayer_Stop(m_playerHandle);
}

void ADX2Player::pause()
{
	criAtomExPlayer_Pause(this->m_playerHandle, CRI_TRUE);
}

void ADX2Player::resume()
{
	criAtomExPlayer_Pause(this->m_playerHandle, CRI_FALSE);
}


// 再生位置の指定
void ADX2Player::setStartTime(CriSint64 startTime)
{
	criAtomExPlayer_SetStartTime(m_playerHandle, startTime);
}


// 再生時刻取得
CriSint64 ADX2Player::getTime()const
{
	return criAtomExPlayer_GetTime(m_playerHandle);
}


// プレイヤーハンドルの取得
CriAtomExPlayerHn ADX2Player::getPlayerHandle()const
{
	return m_playerHandle;
}


// 再生ステータスの取得
CriAtomExPlayerStatus ADX2Player::getStatus()const
{
	return criAtomExPlayer_GetStatus(m_playerHandle);
}

// 再生位置変更
void ADX2Player::seekPlayTime(CriSint64 time)
{
	this->stop();
	this->setStartTime(time);
	this->start();
}
