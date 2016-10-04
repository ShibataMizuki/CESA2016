#pragma once

#include<memory>
#include<functional>

class CSBody;

//! 衝突した後の処理
class CSHitCallback
{
	/*==============================
	コンストラクタ
	===============================*/
public:
	CSHitCallback(int collisionGroupA, int collisionGroupB);

	/*==============================
	衝突グループの管理
	===============================*/
private:
	int m_collisionGroupA;
	int m_collisionGroupB;
public:
	//! 衝突グループAを設定
	void setCollisionGroupA(int group);
	//! 衝突グループBを設定
	void setCollisionGroupB(int group);
	//! 衝突グループAを取得
	int getCollisionGroupA()const;
	//! 衝突グループBを取得
	int getCollisionGroupB()const;

public:
	//! 衝突直後の処理
	std::function<void(const std::shared_ptr<CSBody>& bodyA, const std::shared_ptr<CSBody>& bodyB)> HitBegin;

	//! スマートポインタ生成
	static std::shared_ptr<CSHitCallback> createShared(int collisionGroupA, int collisionGroupB);
};