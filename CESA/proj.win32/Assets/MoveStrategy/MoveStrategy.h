/*////////////////////////////////////////////////////////
[ファイル名]
[概要]
[作成者]
[更新日]
////////////////////////////////////////////////////////*/
#pragma once

class GameObject;

class MoveStrategy
{
protected:
	// 操作対象
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
	[概要]
	更新処理
	[引数]
	前フレームからの経過時間 : dt
	[戻り値]
	なし
	===============================*/
	virtual void update(float dt) = 0;

};