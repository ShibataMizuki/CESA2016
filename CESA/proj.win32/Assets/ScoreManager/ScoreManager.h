#pragma once

class ScoreManager
{
private:
	/*==============================
	ctor
	===============================*/
	ScoreManager() { m_score = 0; }
	~ScoreManager() {}
	ScoreManager(ScoreManager&) = delete;
	ScoreManager(ScoreManager&&) = delete;
	ScoreManager& operator=(ScoreManager&) = delete;

private:

	static ScoreManager* m_pInstance;

public:
	/*==============================
	singleton
	===============================*/
	static ScoreManager* getInstance();
	void release();

	/*==============================
	getter
	===============================*/

	/*==============================
	method
	===============================*/
	void update();
	
	/*==============================
	���j���̃J�E���g
	===============================*/
private:
	int m_enemyShootingDownCount;
public:
	void addEnemyShootingDownCount();
	int getEnemyShootingDownCount()const;
	void resetEnemyShootingDownCount();

	/*==============================
	�X�R�A�̊Ǘ�
	===============================*/
private:
	float m_score;
	float m_scoreBuffer;
public:
	float getScore()const;
	void addScore(float value);
	void resetScore();

	/*==============================
	������
	===============================*/
public:
	void init();
};