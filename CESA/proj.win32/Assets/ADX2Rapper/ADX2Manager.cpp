
#include "ADX2Manager.h"
#include"ADX2Player.h"
#include"DebugNode/DebugNode.h"

ADX2Manager* ADX2Manager::m_pInstance = nullptr;

//! エラーコールバック
static void UserErrorCallBack(const CriChar8* errid, CriUint32 p1, CriUint32 p2, CriUint32* parray)
{
	const CriChar8* errmsg;
	std::string msg = "ErrorCallBack:";
	//! エラーコードから文字列に変換してコンソール出力する
	msg += criErr_ConvertIdToMessage(errid, p1, p2);
	cocos2d::log("%s\n", msg.c_str());
	return;
}

//! ユーザ定義メモリアロケータ
void* UserAlloc(void* obj, CriUint32 size)
{
	void* ptr;
	ptr = malloc(size);
	return ptr;
}

//! ユーザ定義メモリ解放
void UserFree(void* obj, void *ptr)
{
	free(ptr);
}



ADX2Manager::ADX2Manager()
{
}


ADX2Manager::~ADX2Manager()
{
}


bool ADX2Manager::initialize(const std::string& configFilePath)
{
	//! ボイスプールハンドル
	CriAtomExVoicePoolHn voicePool;
	//! D-BASハンドル
	CriAtomDbasId dbas;

	//! エラーコールバック関数の登録
	criErr_SetCallback(UserErrorCallBack);
	//! メモリアロケータの登録
	criAtomEx_SetUserAllocator(UserAlloc, UserFree, NULL);
	//! ライブラリ初期化
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	criAtomEx_Initialize_WASAPI(NULL, NULL, 0);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	criAtomEx_Initialize_ANDROID(NULL, NULL, 0);

	/* 以下、Androidで必要な処理。JNIを介してActivityのContextオブジェクトを取得する */
	cocos2d::JniMethodInfo methodInfo;
	cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/lib/Cocos2dxActivity", "getContext", "()Landroid/content/Context;");
	auto android_context_object = (jobject)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);

	/* assetsフォルダへのアクセスを有効化する */
	criFs_EnableAssetsAccess_ANDROID(cocos2d::JniHelper::getJavaVM(), android_context_object);
#endif


	//! ストリーミング用バッファの作成
	dbas = criAtomDbas_Create(NULL, NULL, 0);
	//! 全体設定ファイルの登録
	criAtomEx_RegisterAcfFile(NULL, configFilePath.c_str(), NULL, 0);
	//! DSPバスの設定の登録
	criAtomEx_AttachDspBusSetting("DspBusSetting_0", NULL, 0);
	//! ボイスプールの作成
	CriAtomExStandardVoicePoolConfig vpConfig;
	criAtomExVoicePool_SetDefaultConfigForStandardVoicePool(&vpConfig);
	vpConfig.player_config.streaming_flag = CRI_TRUE;
	voicePool = criAtomExVoicePool_AllocateStandardVoicePool(&vpConfig, NULL, 0);
	return true;
}

CriAtomExPlayerHn ADX2Manager::createPlayer()
{
	return criAtomExPlayer_Create(NULL, NULL, 0);
}

CriAtomExAcbHn ADX2Manager::loadCueSheet(const std::string& queSheetPath)
{
	return criAtomExAcb_LoadAcbFile(NULL, queSheetPath.c_str(), NULL, NULL, NULL, NULL);
}

void ADX2Manager::setCueId(CriAtomExPlayerHn playerHandle, CriAtomExAcbHn cueSheetHandle, CriAtomExCueId id)
{
	criAtomExPlayer_SetCueId(playerHandle, cueSheetHandle, id);
}

// プレイヤーの作成
ADX2Player* ADX2Manager::createPlayer(CriAtomExAcbHn acbHandle, CriAtomExCueId id)
{
	return new ADX2Player(acbHandle, id);
}


// ADX2毎フレーム処理
void ADX2Manager::executeMain()
{
	criAtomEx_ExecuteMain();
}