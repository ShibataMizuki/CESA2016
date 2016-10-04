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
	撃破数のカウント
	===============================*/
private:
	int m_enemyShootingDownCount;
public:
	void addEnemyShootingDownCount();
	int getEnemyShootingDownCount()const;
	void resetEnemyShootingDownCount();

	/*==============================
	スコアの管理
	===============================*/
private:
	float m_score;
	float m_scoreBuffer;
public:
	float getScore()const;
	void addScore(float value);
	void resetScore();

	/*==============================
	初期化
	===============================*/
public:
	void init();
};