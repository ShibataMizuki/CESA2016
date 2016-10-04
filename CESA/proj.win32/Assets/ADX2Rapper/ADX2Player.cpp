#include "ADX2Player.h"



ADX2Player::ADX2Player(CriAtomExAcbHn acbHandle, CriAtomExCueId cueId)
{
	m_playerHandle = criAtomExPlayer_Create(NULL, NULL, 0);
	criAtomExPlayer_SetCueId(m_playerHandle, acbHandle, cueId);
}


ADX2Player::~ADX2Player()
{
}


// �Đ��̊J�n
CriAtomExPlaybackId ADX2Player::start()
{
	return criAtomExPlayer_Start(m_playerHandle);
}


// �Đ�����
CriAtomExPlaybackId ADX2Player::prepare()
{
	return criAtomExPlayer_Prepare(m_playerHandle);
}

// �Đ���~
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


// �Đ��ʒu�̎w��
void ADX2Player::setStartTime(CriSint64 startTime)
{
	criAtomExPlayer_SetStartTime(m_playerHandle, startTime);
}


// �Đ������擾
CriSint64 ADX2Player::getTime()const
{
	return criAtomExPlayer_GetTime(m_playerHandle);
}


// �v���C���[�n���h���̎擾
CriAtomExPlayerHn ADX2Player::getPlayerHandle()const
{
	return m_playerHandle;
}


// �Đ��X�e�[�^�X�̎擾
CriAtomExPlayerStatus ADX2Player::getStatus()const
{
	return criAtomExPlayer_GetStatus(m_playerHandle);
}

// �Đ��ʒu�ύX
void ADX2Player::seekPlayTime(CriSint64 time)
{
	this->stop();
	this->setStartTime(time);
	this->start();
}
