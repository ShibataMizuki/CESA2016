#pragma once

#include<cocos2d.h>

class GameObject;
class PlayerPlane;
class EnemyPlane;
class PlayerBullet;
class EnemyBullet;
class ScoreItem;
class ADX2Player;

class GameObjectManager
{
	/*==============================
	シングルトン化
	===============================*/
private:
	GameObjectManager() = default;
	~GameObjectManager() = default;
	GameObjectManager(const GameObjectManager&) = delete;
	GameObjectManager(const GameObjectManager&&) = delete;
	GameObjectManager& operator=(const GameObjectManager&) = delete;
	static GameObjectManager* m_instance;
public:
	static GameObjectManager* getInstance();
	void release();

	/*==============================
	ターゲットノードの管理
	===============================*/
private:
	cocos2d::Node* m_pTargetNode;
public:
	void setTargetNode(cocos2d::Node* pTargetNode);
	cocos2d::Node* getTargetNode()const;

	/*==============================
	GameObjectの管理
	===============================*/
private:
	std::list<GameObject*> m_gameObjectList;
	PlayerPlane* m_pPlayerPlane;
	std::list<EnemyPlane*> m_enemyPlaneList;
	std::list<PlayerBullet*> m_playerBulletList;
	std::list<EnemyBullet*> m_enemyBulletList;
	std::list<ScoreItem*> m_scoreItemList;
	std::list<GameObject*> m_removeList;
	//! @brief オブジェクトのグループ分け
	void grouping(GameObject* pGameObject);
	//! @brief すべてのリストからオブジェクトを開放する
	void removeToAllList(GameObject* pGameObject);
	//! @brief 画面からのはみ出しチェック
	void checkScreenOut();
	//! @brief オブジェクトの解放処理
	void executeRemoving();
public:
	//! @brief オブジェクト追加
	void addGameObject(GameObject* pGameObject);
	//! @brief オブジェクト解放
	void removeObject(GameObject* pGameObject);
	//! @brief オブジェクトの生存チェック
	bool isArrive(GameObject* pGameObject);

	/*==============================
	GameObjectのgetter関数
	===============================*/
public:
	PlayerPlane* getPlayerPlane()const;
	const std::list<EnemyPlane*>& getEnemyList()const;
	const std::list<EnemyBullet*>& getEnemyBulletList()const;
	const std::list<ScoreItem*>& getScoreItemList()const;
	const std::list<PlayerBullet*>& getPlayerBullet()const;

	/*==============================
	当たり判定の処理
	===============================*/
private:
	//! @brief 自機弾と敵機の当たり判定
	void checkCollisionPlayerBulletToEnemyPlane();
	//! @brief 自機と敵弾の当たり判定
	void checkCollisionPlayerToEnemyBullet();
	//! @brief 自機とスコアアイテムの当たり判定
	void checkCollisionPlayerToScoreItem();

	/*==============================
	更新処理
	===============================*/
public:
	void update(float dt);
	

	/*==============================
	効果音
	===============================*/
private:
	ADX2Player* m_pItemHitPlayer;
public:
	//! @brief 効果音をセット
	void setItemHitPlayer(ADX2Player* pPlayer);

	//! @brief マネージャのリセット
	void reset();
};