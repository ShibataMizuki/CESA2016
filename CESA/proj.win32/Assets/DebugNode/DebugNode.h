#pragma once

#include<cocos2d.h>
#include<vector>

//! デバッグ表示クラス
class DebugStringNode
{
	/*==============================
	シングルトン関係
	===============================*/
private:
	static DebugStringNode* m_pInstance;
	DebugStringNode() = default;
	~DebugStringNode() = default;
	DebugStringNode(DebugStringNode&) = delete;
	DebugStringNode(DebugStringNode&&) = delete;
	DebugStringNode* operator=(DebugStringNode&) = delete;

public:
	//! @brief 唯一のインスタンスを取得する
	static DebugStringNode* getInstance();
	//! @brief インスタンスの開放をする
	void release();

	/*==============================
	デバッグ文字列機能
	===============================*/
private:
	std::vector<cocos2d::Label*> m_debugStrList;
	std::vector<std::string> m_stringBuffer;

	cocos2d::Node* m_pTargetNode;
public:
	//! @brief 初期化処理
	void init(cocos2d::Node* pTargetNode);
	//! @brief 更新処理
	void update();
	//! @brief デバッグ文字をセットする
	void printDebugString(std::string debugString);
};