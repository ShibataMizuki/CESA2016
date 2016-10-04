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
	ボディの管理
	===============================*/
private:
	std::list<std::shared_ptr<CSBody>> m_bodyList;
public:
	//! ボディの追加
	void addBody(const std::shared_ptr<CSBody>& pBody);

	//! ボディの削除
	bool destroyBody(const std::shared_ptr<CSBody>& pBody);
	
	//! ボディのリストを取得
	const std::list < std::shared_ptr<CSBody>>& getBodyList(int group)const;
	std::list <std::shared_ptr<CSBody>> getBodyList();

	/*==============================
	衝突コールバックの管理
	===============================*/
private:
	std::list<std::shared_ptr<CSHitCallback>> m_hitCallbackList;
public:
	//! 衝突コールバック追加
	void addHitCallback(const std::shared_ptr<CSHitCallback>& pCallback);
	//! 衝突コールバックリストの先頭イテレータを取得
	std::list<std::shared_ptr<CSHitCallback>>::iterator getCallbackListBegin();
	//! 衝突コールバックリストの末尾イテレータを取得
	std::list<std::shared_ptr<CSHitCallback>>::iterator getCallbackListEnd();
	//! 衝突コールバックリストを取得
	const std::list < std::shared_ptr<CSHitCallback>>& getCallbackList()const;
	//! 衝突コールバックをすべて解放
	void removeAllCallback();

	/*==============================

	===============================*/
private:
	//! ボディハッシュ
	std::map<int, std::list<std::shared_ptr<CSBody>>> m_bodyMap;

	/*==============================

	===============================*/
private:
	//! executeCollision()の補助関数
	bool isCollision(CSBody* bodyA, CSBody* bodyB);
public:
	//! 衝突判定および衝突コールバックを処理
	void executeCollision();
};