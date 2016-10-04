/*////////////////////////////////////////////////////////
[�t�@�C����]
GameObject.h
[�T�v]
�Q�[���I�u�W�F�N�g�̒�`
[�쐬��]
[�X�V��]
2016-05-26
////////////////////////////////////////////////////////*/
#pragma once

#include<cocos2d.h>
#include<functional>
#include<vector>
#include<memory>
#include"CollisionSystem/CSBody/CSBody.h"
//#include"MoveStrategy/MoveStrategy.h"

class MoveStrategy;
class CollisionShape;


enum class ObjectType : int
{
	Player,
	PlayerBullet,
	Enemy,
	EnemyBullet,
	Item
};

/*
<<<override>>>
init()
update(float)
*/
class GameObject :public cocos2d::Node
{
	/*==============================
	cocos2d-x�I�[�o�[���C�h
	===============================*/
public:
	bool init()override;
	void update(float dt)override;

	/*==============================
	�R���X�g���N�^
	===============================*/
public:
	GameObject() :
		m_pBody(nullptr),
		m_removeFlag(false),
		m_pMoveStrategy(nullptr) {}

	~GameObject();

	/*==============================
	�����蔻��`��̊Ǘ�
	===============================*/
	/*
private:
	std::shared_ptr<CollisionShape> m_pShape;
public:
	void setShape(const std::shared_ptr<CollisionShape>& pShape);
	const std::shared_ptr<CollisionShape>& getShape()const;
	*/
	/*==============================
	�{�f�B�̊Ǘ�
	===============================*/
private:
	std::shared_ptr<CSBody> m_pBody;
public:
	void setBody(const std::shared_ptr<CSBody>& pBody);
	const std::shared_ptr<CSBody>& getBody()const;

	/*==============================
	�ړ��p�X�g���e�W�̊Ǘ�
	===============================*/
private:
	std::shared_ptr<MoveStrategy> m_pMoveStrategy;
public:
	void setMoveStrategy(const std::shared_ptr<MoveStrategy>& pMoveStrategy);
	const std::shared_ptr<MoveStrategy>& getMoveStrategy()const;

	/*==============================
	�����[�u�t���O�̊Ǘ�
	===============================*/
private:
	bool m_removeFlag;
public:
	void setRemoveFlag(bool flag);
	bool getRemoveFlag()const;
};