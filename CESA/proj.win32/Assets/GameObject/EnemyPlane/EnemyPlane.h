/*////////////////////////////////////////////////////////
[�t�@�C����]
[�T�v]
[�쐬��]
[�X�V��]
[���l]
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
	GameObject�I�[�o�[���C�h
	===============================*/
public:
	CREATE_FUNC(EnemyPlane);
	~EnemyPlane();
	bool init()override;
	void update(float dt)override;

	/*==============================
	�A�N�V��������
	===============================*/
private:
	//! @brief �A�N�V�����҂��s��
	std::queue<std::shared_ptr<EnemyAction>> m_actionQueue;
public:
	//! @brief �A�N�V��������
	void executeAction(float dt);
	//! @brief �V�����A�N�V�������v�b�V������
	void pushAction(const std::shared_ptr<EnemyAction>& action);

	/*==============================
	�X�R�A�Ǘ�
	===============================*/
private:
	int m_scoreToHave;
public:
	//! @brief �X�R�A���Z�b�g
	void setScoreToHave(int value);
	//! @brief �X�R�A���擾
	int getScoreToHave()const;

	/*==============================
	�摜�̊Ǘ�
	===============================*/
private:
	cocos2d::Sprite* m_pSprite;
public:
	//! @brief �X�v���C�g���Z�b�g
	void setSprite(cocos2d::Sprite* sprite);
	//! @brief �X�v���C�g���擾
	cocos2d::Sprite* getSprite()const;
	/*==============================
	���C�t�Ǘ�
	===============================*/
private:
	float m_life;
public:
	//! @brief ���C�t���Z�b�g
	void setLife(float value);
	//! @brief ���C�t���擾
	float getLife()const;
};