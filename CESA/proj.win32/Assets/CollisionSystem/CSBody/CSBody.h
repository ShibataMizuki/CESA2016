#pragma once

#include<list>
#include<memory>
#include<string>
#include"../CSShape/CSShape.h"

class CSBody
{
	/*==============================
	コンストラクタ
	===============================*/
public:
	CSBody();

	/*==============================
	座標の管理
	===============================*/
protected:
	CSVec2 m_pos;
public:
	//! 座標を設定
	void setPosition(const CSVec2& pos);
	//! 座標を取得
	const CSVec2& getPosition()const;

	/*==============================
	角度の管理
	===============================*/
protected:
	float m_angle;
public:
	//! 角度を設定
	void setAngle(float angle);
	//! 角度を取得
	float getAngle()const;

	/*==============================
	図形リストの管理
	===============================*/
protected:
	std::list<std::shared_ptr<CSShape>> m_shapeList;
public:
	//! 図形情報を追加
	void addShape(const std::shared_ptr<CSShape>& pShape);
	//! 図形リストを取得
	const std::list<std::shared_ptr<CSShape>>& getShapeList()const;
	//! 図形リストの先頭イテレータを取得
	std::list<std::shared_ptr<CSShape>>::iterator getShapeBegin();
	//! 図形リストの末尾イテレータを取得
	std::list<std::shared_ptr<CSShape>>::iterator getShapeEnd();

	/*==============================
	衝突グループの管理
	===============================*/
protected:
	int m_collisionGroup;
public:
	//! 衝突グループを設定
	void setCollisionGroup(int group);
	//! 衝突グループを取得
	int getCollisionGroup()const;

	/*==============================
	タグの管理
	===============================*/
protected:
	std::string m_tag;
public:
	//! タグを設定
	void setTag(const std::string& tag);
	//! タグを取得
	std::string getTag()const;

	/*==============================
	ユーザーデータの管理
	===============================*/
protected:
	void* m_pUserData;
public:
	//! ユーザーデータを設定
	void setUserData(void* pUserData);
	//! ユーザーデータを取得
	void* getUserData()const;
	//! キャスト済みのユーザーデータを取得
	template<class T>
	T getCastedUserData()const;

	////////////////////////////////////////
public:
	//! スマートポインタ作成
	static std::shared_ptr<CSBody> createShared(const CSVec2& pos);
	static std::shared_ptr<CSBody> createShared();
};

template<class T>
inline T CSBody::getCastedUserData() const
{
	return static_cast<T>(m_pUserData);
}
