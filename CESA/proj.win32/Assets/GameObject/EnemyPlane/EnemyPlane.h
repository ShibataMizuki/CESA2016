/*////////////////////////////////////////////////////////
[ファイル名]
[概要]
[作成者]
[更新日]
[備考]
////////////////////////////////////////////////////////*/

#pragma once

#include<memory>
#include<queue>
#include"GameObject/GameObject.h"

class EnemyAI;
class EnemyAttack;
class EnemyAction;

class EnemyPlane : public GameObject
{
	/*==============================
	GameObjectオーバーライド
	===============================*/
public:
	CREATE_FUNC(EnemyPlane);
	~EnemyPlane();
	bool init()override;
	void update(float dt)override;

	/*==============================
	アクション処理
	===============================*/
private:
	//! @brief アクション待ち行列
	std::queue<std::shared_ptr<EnemyAction>> m_actionQueue;
public:
	//! @brief アクション処理
	void executeAction(float dt);
	//! @brief 新しいアクションをプッシュする
	void pushAction(const std::shared_ptr<EnemyAction>& action);

	/*==============================
	スコア管理
	===============================*/
private:
	int m_scoreToHave;
public:
	//! @brief スコアをセット
	void setScoreToHave(int value);
	//! @brief スコアを取得
	int getScoreToHave()const;

	/*==============================
	画像の管理
	===============================*/
private:
	cocos2d::Sprite* m_pSprite;
public:
	//! @brief スプライトをセット
	void setSprite(cocos2d::Sprite* sprite);
	//! @brief スプライトを取得
	cocos2d::Sprite* getSprite()const;
	/*==============================
	ライフ管理
	===============================*/
private:
	float m_life;
public:
	//! @brief ライフをセット
	void setLife(float value);
	//! @brief ライフを取得
	float getLife()const;
};