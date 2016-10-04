#pragma once

#include"ADX2Manager.h"
#include"ADX2Player.h"

// ADX2サポート関数
namespace ADX2Util
{
	/*==============================
	[概要]
	ミリ秒を秒に変換する
	[引数]
	変換する値(ミリ秒) : milSec
	[戻り値]
	変換後の値(秒) : float
	===============================*/
	constexpr float convertToSec(CriSint64 milSec)
	{
		return milSec / 1000.f;
	}

	constexpr CriSint64 convertToCriSint64(float sec)
	{
		return (CriSint64)(sec * 1000);
	}
}
