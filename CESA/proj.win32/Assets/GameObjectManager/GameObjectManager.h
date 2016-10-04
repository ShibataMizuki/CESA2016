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
	�V���O���g����
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
	�^�[�Q�b�g�m�[�h�̊Ǘ�
	===============================*/
private:
	cocos2d::Node* m_pTargetNode;
public:
	void setTargetNode(cocos2d::Node* pTargetNode);
	cocos2d::Node* getTargetNode()const;

	/*==============================
	GameObject�̊Ǘ�
	===============================*/
private:
	std::list<GameObject*> m_gameObjectList;
	PlayerPlane* m_pPlayerPlane;
	std::list<EnemyPlane*> m_enemyPlaneList;
	std::list<PlayerBullet*> m_playerBulletList;
	std::list<EnemyBullet*> m_enemyBulletList;
	std::list<ScoreItem*> m_scoreItemList;
	std::list<GameObject*> m_removeList;
	//! @brief �I�u�W�F�N�g�̃O���[�v����
	void grouping(GameObject* pGameObject);
	//! @brief ���ׂẴ��X�g����I�u�W�F�N�g���J������
	void removeToAllList(GameObject* pGameObject);
	//! @brief ��ʂ���̂͂ݏo���`�F�b�N
	void checkScreenOut();
	//! @brief �I�u�W�F�N�g�̉������
	void executeRemoving();
public:
	//! @brief �I�u�W�F�N�g�ǉ�
	void addGameObject(GameObject* pGameObject);
	//! @brief �I�u�W�F�N�g���
	void removeObject(GameObject* pGameObject);
	//! @brief �I�u�W�F�N�g�̐����`�F�b�N
	bool isArrive(GameObject* pGameObject);

	/*==============================
	GameObject��getter�֐�
	===============================*/
public:
	PlayerPlane* getPlayerPlane()const;
	const std::list<EnemyPlane*>& getEnemyList()const;
	const std::list<EnemyBullet*>& getEnemyBulletList()const;
	const std::list<ScoreItem*>& getScoreItemList()const;
	const std::list<PlayerBullet*>& getPlayerBullet()const;

	/*==============================
	�����蔻��̏���
	===============================*/
private:
	//! @brief ���@�e�ƓG�@�̓����蔻��
	void checkCollisionPlayerBulletToEnemyPlane();
	//! @brief ���@�ƓG�e�̓����蔻��
	void checkCollisionPlayerToEnemyBullet();
	//! @brief ���@�ƃX�R�A�A�C�e���̓����蔻��
	void checkCollisionPlayerToScoreItem();

	/*==============================
	�X�V����
	===============================*/
public:
	void update(float dt);
	

	/*==============================
	���ʉ�
	===============================*/
private:
	ADX2Player* m_pItemHitPlayer;
public:
	//! @brief ���ʉ����Z�b�g
	void setItemHitPlayer(ADX2Player* pPlayer);

	//! @brief �}�l�[�W���̃��Z�b�g
	void reset();
};