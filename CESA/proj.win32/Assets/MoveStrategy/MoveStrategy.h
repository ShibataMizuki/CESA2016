/*////////////////////////////////////////////////////////
[�t�@�C����]
[�T�v]
[�쐬��]
[�X�V��]
////////////////////////////////////////////////////////*/
#pragma once

class GameObject;

class MoveStrategy
{
protected:
	// ����Ώ�
	GameObject* m_pTargetObject;

public:
	/*==============================
	ctor
	===============================*/
	MoveStrategy(GameObject* pTargetObject);

	/*==============================
	~ctor
	===============================*/
	virtual ~MoveStrategy();

	/*==============================
	setter
	===============================*/
	void setTargetObject(GameObject* pTargetObject);

	/*==============================
	getter
	===============================*/
	GameObject* getTargetObject()const;

	/*==============================
	method
	===============================*/

	/*==============================
	[�T�v]
	�X�V����
	[����]
	�O�t���[������̌o�ߎ��� : dt
	[�߂�l]
	�Ȃ�
	===============================*/
	virtual void update(float dt) = 0;

};