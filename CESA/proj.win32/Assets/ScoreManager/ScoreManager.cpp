#include "ScoreManager.h"

ScoreManager* ScoreManager::m_pInstance = nullptr;

ScoreManager * ScoreManager::getInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new ScoreManager();
	}
	return m_pInstance;
}

void ScoreManager::release()
{
	delete m_pInstance;
}

float ScoreManager::getScore() const
{
	return m_score;
}

void ScoreManager::addScore(float value)
{
	m_scoreBuffer += value;
}

void ScoreManager::resetScore()
{
	m_score = 0.f;
	m_scoreBuffer = 0.f;
}

void ScoreManager::init()
{
	m_score = 0.f;
	m_scoreBuffer = 0.f;
	m_enemyShootingDownCount = 0;
}

void ScoreManager::update()
{
	m_score += m_scoreBuffer / 20;
	m_scoreBuffer -= m_scoreBuffer / 20;
}

void ScoreManager::addEnemyShootingDownCount()
{
	m_enemyShootingDownCount++;
}

int ScoreManager::getEnemyShootingDownCount() const
{
	return m_enemyShootingDownCount;
}

void ScoreManager::resetEnemyShootingDownCount()
{
	m_enemyShootingDownCount = 0;
}
