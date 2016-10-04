/*////////////////////////////////////////////////////////
[ファイル名]
ADX2Player.h
[概要]
cri_adx2le CriAtomExPlayerラッパー
[作成者]
柴田瑞己
[更新日]
2016/05/06
////////////////////////////////////////////////////////*/
#pragma once

#include"ADX2Manager.h"

class ADX2Player
{
private:
	// プレイヤーハンドル
	CriAtomExPlayerHn m_playerHandle;

public:
	/*==============================
	[概要]
	コンストラクタ
	[引数]
	キューハンドル : CriAtomExAcbHn
	キューID : CriAtomExCueId
	[戻り値]
	なし
	===============================*/
	ADX2Player(CriAtomExAcbHn acbHandle, CriAtomExCueId cueId);


	/*==============================
	[概要]
	デストラクタ
	[引数]
	なし
	[戻り値]
	なし
	===============================*/
	~ADX2Player();


	/*==============================
	[概要]
	再生開始
	[引数]
	なし
	[戻り値]
	プレイバックID : CriAtomExPlaybackId
	===============================*/
	CriAtomExPlaybackId start();
	

	/*==============================
	[概要]
	再生準備
	[引数]
	なし
	[戻り値]
	プレイバックID : CriAtomExPlaybackId
	===============================*/
	CriAtomExPlaybackId prepare();

	/*==============================
	[概要]
	再生停止
	[引数]
	なし
	[戻り値]
	なし
	===============================*/
	void stop();

	void pause();
	void resume();

	/*==============================
	[概要]
	再生時間の指定
	[引数]
	再生時間(ミリ秒) : CriSint64
	[戻り値]
	なし
	===============================*/
	void setStartTime(CriSint64 startTime);

	/*==============================
	[概要]
	再生時間の取得
	[引数]
	なし
	[戻り値]
	再生時間(ミリ秒) : CriSint64
	===============================*/
	CriSint64 getTime()const;
	
	/*==============================
	[概要]
	プレイヤーハンドルの取得
	[引数]
	なし
	[戻り値]
	プレイヤーハンドル : CriAtomExPlayerHn
	===============================*/
	CriAtomExPlayerHn getPlayerHandle()const;

	/*==============================
	[概要]
	ステータスの取得
	[引数]
	なし
	[戻り値]
	ステータス : CriAtomExPlayerStatus
	===============================*/
	CriAtomExPlayerStatus getStatus()const;

	
	/*==============================
	[概要]
	現在再生位置を変更する(シークする)
	[引数]
	再生位置(ミリ秒) : CriSint64
	[戻り値]
	なし
	===============================*/
	void seekPlayTime(CriSint64 time);
};