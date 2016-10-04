#pragma once
#include<cocos2d.h>
#include"CollisionSystem/CSWorld/CSWorld.h"

class WorldManager
{
	/*==============================
	�V���O���g����
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
	world�Ǘ�
	===============================*/
private:
	std::shared_ptr<CSWorld> m_pWorld;
public:
	//! ���[���h����
	void createWorld();
	//! ���[���h�擾
	const std::shared_ptr<CSWorld>& getWorld()const;

	/*==============================
	�f�o�b�O�`��
	===============================*/
private:
	cocos2d::DrawNode* m_pDrawNode;
public:
	void setDrawNode(cocos2d::Layer* pLayer);
	void debugDraw();
};