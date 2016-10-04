#pragma once

#include<cocos2d.h>
#include<vector>

//! �f�o�b�O�\���N���X
class DebugStringNode
{
	/*==============================
	�V���O���g���֌W
	===============================*/
private:
	static DebugStringNode* m_pInstance;
	DebugStringNode() = default;
	~DebugStringNode() = default;
	DebugStringNode(DebugStringNode&) = delete;
	DebugStringNode(DebugStringNode&&) = delete;
	DebugStringNode* operator=(DebugStringNode&) = delete;

public:
	//! @brief �B��̃C���X�^���X���擾����
	static DebugStringNode* getInstance();
	//! @brief �C���X�^���X�̊J��������
	void release();

	/*==============================
	�f�o�b�O������@�\
	===============================*/
private:
	std::vector<cocos2d::Label*> m_debugStrList;
	std::vector<std::string> m_stringBuffer;

	cocos2d::Node* m_pTargetNode;
public:
	//! @brief ����������
	void init(cocos2d::Node* pTargetNode);
	//! @brief �X�V����
	void update();
	//! @brief �f�o�b�O�������Z�b�g����
	void printDebugString(std::string debugString);
};