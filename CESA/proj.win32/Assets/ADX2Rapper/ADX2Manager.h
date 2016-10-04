/*////////////////////////////////////////////////////////
[ファイル名]
ADX2Manager.h
[概要]
ADX2Managerの定義
[作成者]
柴田瑞己
[更新日]
2016/05/08
////////////////////////////////////////////////////////*/

#pragma once
#include<string>
#include<cocos2d.h>
#include"cri_adx2le.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include"cri_le_atom_pc.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include"cri_le_atom_android.h"
#endif

class ADX2Player;

class ADX2Manager
{
private:
	// 唯一のインスタンス
	static ADX2Manager* m_pInstance;

	ADX2Manager();
	ADX2Manager(const ADX2Manager&) = delete;
	ADX2Manager(const ADX2Manager&&) = delete;
	ADX2Manager operator=(const ADX2Manager&) = delete;
	~ADX2Manager();

public:
	/*==============================
	[概要]
	ADX2Managerのインスタンスを取得する
	[引数]
	なし
	[戻り値]
	ADX2Managerのインスタンス : ADX2Manager*
	===============================*/
	static ADX2Manager* getInstance()
	{
		if (m_pInstance == nullptr)m_pInstance = new ADX2Manager();
		return m_pInstance;
	}


	/*==============================
	[概要]
	ADX2Managerのインスタンスを開放します
	[引数]
	なし
	[戻り値]
	なし
	[備考]
	プログラム終了時とかに呼んでください
	===============================*/
	void release()
	{
		delete m_pInstance;
	}


	/*==============================
	[概要]
	ADX2の初期化処理
	[引数]
	コンフィグファイルへのパス : const string&
	[戻り値]
	初期化成功の可否 : bool
	===============================*/
	bool initialize(const std::string& configFilePath);


	/*==============================
	[概要]
	プレイヤーハンドルの生成
	[引数]
	なし
	[戻り値]
	プレイヤーハンドル : CriAtomExPlayerHn
	[備考]
	旧版。非推奨
	===============================*/
	CriAtomExPlayerHn createPlayer();


	/*==============================
	[概要]
	ADX2Playerの生成
	[引数]
	acbハンドル : CriAtomExAcbHn
	キューID : CriAtomExCueId
	[戻り値]
	ADX2Playerのアドレス : ADX2Player*
	===============================*/
	ADX2Player* createPlayer(CriAtomExAcbHn acbHandle, CriAtomExCueId id);

	
	/*==============================
	[概要]
	キューシートの読み込み
	[引数]
	キューシート(.acbファイル)へのパス : const string&
	[戻り値]
	Acbハンドル : CriAtomExAcbHn
	===============================*/
	CriAtomExAcbHn loadCueSheet(const std::string& cueSheetPath);

	
	/*==============================
	[概要]
	キューIDをプレイヤーと紐つける
	[引数]
	プレイヤーハンドル : CriAtomExPlayerHn
	キューシートのハンドル : CriAtomExAcbHn
	キューID : CriAtomExCueId
	[戻り値]
	なし
	===============================*/
	void setCueId(CriAtomExPlayerHn playerHandle, CriAtomExAcbHn cueSheetHandle, CriAtomExCueId id);

	
	/*==============================
	[概要]
	ADX2毎フレーム処理の呼び出し
	[引数]
	なし
	[戻り値]
	なし
	[備考]
	毎フレームこの関数を呼んでください
	===============================*/
	void executeMain();
};

//__declspec(selectany) ADX2Manager* ADX2Manager::m_pInstance = nullptr;