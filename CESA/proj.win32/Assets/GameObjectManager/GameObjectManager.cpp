#include "GameObjectManager.h"
#include"inc/GameObjects.h"
#include"ScoreManager/ScoreManager.h"
#include"CollisionSystem/CSWorld/CSWorld.h"
#include"PopupLabel/PopupLabel.h"
#include"SoundManager/SoundManager.h"
#include"DebugNode/DebugNode.h"
#include"CollisionSystem/CSHitCallback/CSHitCallback.h"
#include"CollisionSystem/CSBody/CSBody.h"

using namespace std;
USING_NS_CC;

GameObjectManager* GameObjectManager::m_instance = nullptr;

GameObjectManager * GameObjectManager::getInstance()
{
	if (!m_instance)
	{
		m_instance = new GameObjectManager();
	}
	return m_instance;
}

void GameObjectManager::release()
{
	delete m_instance;
}

void GameObjectManager::grouping(GameObject * pGameObject)
{
	m_gameObjectList.push_back(pGameObject);
	
	auto pEnemyBullet = dynamic_cast<EnemyBullet*>(pGameObject);
	auto pPlayerBullet = dynamic_cast<PlayerBullet*>(pGameObject);
	auto pScoreItem = dynamic_cast<ScoreItem*>(pGameObject);
	auto pEnemyPlane = dynamic_cast<EnemyPlane*>(pGameObject);
	auto pPlayerPlane = dynamic_cast<PlayerPlane*>(pGameObject);

	if (pEnemyBullet)m_enemyBulletList.push_back(pEnemyBullet);
	else if (pPlayerBullet)m_playerBulletList.push_back(pPlayerBullet);
	else if (pScoreItem)m_scoreItemList.push_back(pScoreItem);
	else if (pEnemyPlane)m_enemyPlaneList.push_back(pEnemyPlane);
	else if (pPlayerPlane)m_pPlayerPlane = pPlayerPlane;
}

void GameObjectManager::removeToAllList(GameObject * pGameObject)
{
	auto pEnemyBullet = dynamic_cast<EnemyBullet*>(pGameObject);
	auto pPlayerBullet = dynamic_cast<PlayerBullet*>(pGameObject);
	auto pScoreItem = dynamic_cast<ScoreItem*>(pGameObject);
	auto pEnemyPlane = dynamic_cast<EnemyPlane*>(pGameObject);
	auto pPlayerPlane = dynamic_cast<PlayerPlane*>(pGameObject);

	if (pEnemyBullet)m_enemyBulletList.remove(pEnemyBullet);
	else if (pPlayerBullet)m_playerBulletList.remove(pPlayerBullet);
	else if (pScoreItem)m_scoreItemList.remove(pScoreItem);
	else if (pEnemyPlane)m_enemyPlaneList.remove(pEnemyPlane);
	else if (pPlayerPlane)m_pPlayerPlane = nullptr;

	m_gameObjectList.remove(pGameObject);
	pGameObject->removeFromParent();
}

void GameObjectManager::checkScreenOut()
{
	auto isOut = [&](const Vec2& pos)
	{
		Size winSize = Director::getInstance()->getVisibleSize();
		if (winSize.width + 400.f<pos.x || -400.f>pos.x)return true;
		if (winSize.height + 400.f<pos.y || -400.f>pos.y)return true;
		return false;
	};

	std::list<GameObject*> removeList;

	for (auto& object : m_gameObjectList)
	{
		if (isOut(object->getPosition()))removeList.push_back(object);
	}

	for (auto& object : removeList)
	{
		removeToAllList(object);
	}
}

void GameObjectManager::executeRemoving()
{
	for (auto elem : m_removeList)
	{
		removeToAllList(elem);
	}
	m_removeList.clear();
}

void GameObjectManager::removeObject(GameObject * pGameObject)
{
	if (find(m_removeList.begin(), m_removeList.end(), pGameObject)==m_removeList.end())
	{
		m_removeList.push_back(pGameObject);
	}
}

bool GameObjectManager::isArrive(GameObject * pGameObject)
{
	if (find(m_gameObjectList.begin(), m_gameObjectList.end(), pGameObject) == m_gameObjectList.end())
	{
		return false;
	}
	return true;
}

void GameObjectManager::addGameObject(GameObject * pGameObject)
{
	this->grouping(pGameObject);
	m_pTargetNode->addChild(pGameObject);
}

void GameObjectManager::checkCollisionPlayerBulletToEnemyPlane()
{
}

void GameObjectManager::checkCollisionPlayerToEnemyBullet()
{
}

void GameObjectManager::checkCollisionPlayerToScoreItem()
{
}

void GameObjectManager::update(float dt)
{
	this->checkScreenOut();
	this->checkCollisionPlayerBulletToEnemyPlane();
	this->checkCollisionPlayerToEnemyBullet();
	this->checkCollisionPlayerToScoreItem();
	this->executeRemoving();

	char buf[128];
	sprintf(buf, "EnemyNum->%d", m_enemyPlaneList.size());

	DebugStringNode::getInstance()->printDebugString(buf);

}

void GameObjectManager::setItemHitPlayer(ADX2Player * pPlayer)
{
	m_pItemHitPlayer = pPlayer;
}

void GameObjectManager::reset()
{
	m_gameObjectList.clear();
	m_enemyBulletList.clear();
	m_enemyPlaneList.clear();
	m_playerBulletList.clear();
	m_pPlayerPlane = nullptr;
	m_scoreItemList.clear();
}

void GameObjectManager::setTargetNode(Node * pTargetNode)
{
	m_pTargetNode = pTargetNode;
}

PlayerPlane * GameObjectManager::getPlayerPlane() const
{
	return m_pPlayerPlane;
}

const std::list<EnemyPlane*>& GameObjectManager::getEnemyList() const
{
	return m_enemyPlaneList;
}

const std::list<EnemyBullet*>& GameObjectManager::getEnemyBulletList() const
{
	return m_enemyBulletList;
}

const std::list<ScoreItem*>& GameObjectManager::getScoreItemList() const
{
	return m_scoreItemList;
}

const std::list<PlayerBullet*>& GameObjectManager::getPlayerBullet() const
{
	return m_playerBulletList;
}

Node * GameObjectManager::getTargetNode() const
{
	return m_pTargetNode;
}