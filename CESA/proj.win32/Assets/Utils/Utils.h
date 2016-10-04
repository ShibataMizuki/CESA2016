/*////////////////////////////////////////////////////////
[ファイル名]
Utils.h
[概要]
サポート関数を実装したヘッダ
[作成者]
柴田瑞己
[更新日]
2016-05-13
////////////////////////////////////////////////////////*/

#pragma once

#include<cocos2d.h>

#define USING_UTIL using namespace Util;

namespace Util
{
	// 円周率
	constexpr static float PI = 3.141592654f;

	/*==============================
	[概要]
	値が指定した範囲内にあるか判定をする
	[引数]
	調べる値 : point
	範囲の最小値 : min
	範囲の最大値 : max
	[戻り値]
	範囲内にあるかどうかの真偽値 : bool
	===============================*/
	template<class T> constexpr bool isInRange(const T& point, const T& min, const T& max)
	{
		return point >= min&&point <= max;
	}

	/*==============================
	[概要]
	弧度法数値を度数法数値に変換する
	[引数]
	弧度法数値 : radian
	[戻り値]
	度数法数値 : float
	===============================*/
	constexpr float convertToDegree(float radian)
	{
		return radian/(PI / 180.f);
	}

	/*==============================
	[概要]
	度数法数値を弧度法数値に変換する
	[引数]
	度数法数値 : degree
	[戻り値]
	弧度法数値 : float
	===============================*/
	constexpr float convertToRadian(float degree)
	{
		return degree*(PI / 180.f);
	}


	cocos2d::Vec2 convertToDirection(float angle);
};