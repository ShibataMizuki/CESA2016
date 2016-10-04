#pragma once
#include<cocos2d.h>
#include"CollisionSystem/CSWorld/CSWorld.h"

class WorldManager
{
	/*==============================
	シングルトン化
	===============================*/
private:
	static WorldManager* m_pInstance;
	WorldManager() = default;
	~WorldManager() = default;
	WorldManager(WorldManager&) = delete;
	WorldManager(WorldManager&&) = delete;
	WorldManager& operator=(WorldManager&) = delete;
public:
	static WorldManager* getInstance();
	void release();

	/*==============================
	world管理
	===============================*/
private:
	std::shared_ptr<CSWorld> m_pWorld;
public:
	//! ワールド生成
	void createWorld();
	//! ワールド取得
	const std::shared_ptr<CSWorld>& getWorld()const;

	/*==============================
	デバッグ描画
	===============================*/
private:
	cocos2d::DrawNode* m_pDrawNode;
public:
	void setDrawNode(cocos2d::Layer* pLayer);
	void debugDraw();
};