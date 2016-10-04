#include"DebugNode/DebugNode.h"
#include "SoundManager.h"


SoundManager* SoundManager::m_pInstance = nullptr;

SoundManager * SoundManager::getInstance()
{
	if (!m_pInstance)m_pInstance = new SoundManager();
	return m_pInstance;
}

void SoundManager::release()
{
	delete m_pInstance;
}

void SoundManager::setBackSound(ADX2Player * pBackSound, float backSoundBPM)
{
	m_pBackSound = pBackSound;
	m_backSoundBPM = backSoundBPM;

	m_beatInterval[0] = ADX2Util::convertToCriSint64(1.f / (backSoundBPM / 60.f))/4.f;
	m_beatInterval[1] = ADX2Util::convertToCriSint64(1.f / (backSoundBPM / 60.f))/2.f;
	m_beatInterval[2] = ADX2Util::convertToCriSint64(1.f / (backSoundBPM / 60.f));
	m_beatInterval[3] = ADX2Util::convertToCriSint64(1.f / (backSoundBPM / 60.f))*2.f;

	for (int f1 = 0; f1 < 4; f1++)
	{
		m_timeToPrevBeat[f1] = 0.f;
	}
}

ADX2Player * SoundManager::getBackSound() const
{
	return m_pBackSound;
}

float SoundManager::getBackSoundBPM() const
{
	return m_backSoundBPM;
}

CriSint64 SoundManager::getBeatInterval(int index) const
{
	return m_beatInterval[index];
}

CriSint64 SoundManager::getTimeToPrevBeat(int index) const
{
	return m_timeToPrevBeat[index];
}

CriSint64 SoundManager::getTimeToNextBeat(int index) const
{
	return m_beatInterval[index] - m_timeToPrevBeat[index];
}

bool SoundManager::isBeat(int index) const
{
	return m_beatFlag[index];
}

void SoundManager::updateTimeToNextBeat()
{
	static CriSint64 oldTime = m_pBackSound->getTime();
	CriSint64 time = m_pBackSound->getTime();
	
	for (int f1 = 0; f1 < 4; f1++)
	{
		m_beatFlag[f1] = false;
		m_timeToPrevBeat[f1] += time - oldTime;
		if (m_timeToPrevBeat[f1] >= m_beatInterval[f1])
		{
			m_timeToPrevBeat[f1] = 0;
			m_beatFlag[f1] = true;
		}
	}
	oldTime = time;

}
