#pragma once

#include<memory>
#include<list>
#include<map>
#include<vector>

class CSBody;
class CSHitCallback;

class CSWorld
{
	/*==============================
	�{�f�B�̊Ǘ�
	===============================*/
private:
	std::list<std::shared_ptr<CSBody>> m_bodyList;
public:
	//! �{�f�B�̒ǉ�
	void addBody(const std::shared_ptr<CSBody>& pBody);

	//! �{�f�B�̍폜
	bool destroyBody(const std::shared_ptr<CSBody>& pBody);
	
	//! �{�f�B�̃��X�g���擾
	const std::list < std::shared_ptr<CSBody>>& getBodyList(int group)const;
	std::list <std::shared_ptr<CSBody>> getBodyList();

	/*==============================
	�Փ˃R�[���o�b�N�̊Ǘ�
	===============================*/
private:
	std::list<std::shared_ptr<CSHitCallback>> m_hitCallbackList;
public:
	//! �Փ˃R�[���o�b�N�ǉ�
	void addHitCallback(const std::shared_ptr<CSHitCallback>& pCallback);
	//! �Փ˃R�[���o�b�N���X�g�̐擪�C�e���[�^���擾
	std::list<std::shared_ptr<CSHitCallback>>::iterator getCallbackListBegin();
	//! �Փ˃R�[���o�b�N���X�g�̖����C�e���[�^���擾
	std::list<std::shared_ptr<CSHitCallback>>::iterator getCallbackListEnd();
	//! �Փ˃R�[���o�b�N���X�g���擾
	const std::list < std::shared_ptr<CSHitCallback>>& getCallbackList()const;
	//! �Փ˃R�[���o�b�N�����ׂĉ��
	void removeAllCallback();

	/*==============================

	===============================*/
private:
	//! �{�f�B�n�b�V��
	std::map<int, std::list<std::shared_ptr<CSBody>>> m_bodyMap;

	/*==============================

	===============================*/
private:
	//! executeCollision()�̕⏕�֐�
	bool isCollision(CSBody* bodyA, CSBody* bodyB);
public:
	//! �Փ˔��肨��яՓ˃R�[���o�b�N������
	void executeCollision();
};