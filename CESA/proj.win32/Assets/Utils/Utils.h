/*////////////////////////////////////////////////////////
[�t�@�C����]
Utils.h
[�T�v]
�T�|�[�g�֐������������w�b�_
[�쐬��]
�ēc����
[�X�V��]
2016-05-13
////////////////////////////////////////////////////////*/

#pragma once

#include<cocos2d.h>

#define USING_UTIL using namespace Util;

namespace Util
{
	// �~����
	constexpr static float PI = 3.141592654f;

	/*==============================
	[�T�v]
	�l���w�肵���͈͓��ɂ��邩���������
	[����]
	���ׂ�l : point
	�͈͂̍ŏ��l : min
	�͈͂̍ő�l : max
	[�߂�l]
	�͈͓��ɂ��邩�ǂ����̐^�U�l : bool
	===============================*/
	template<class T> constexpr bool isInRange(const T& point, const T& min, const T& max)
	{
		return point >= min&&point <= max;
	}

	/*==============================
	[�T�v]
	�ʓx�@���l��x���@���l�ɕϊ�����
	[����]
	�ʓx�@���l : radian
	[�߂�l]
	�x���@���l : float
	===============================*/
	constexpr float convertToDegree(float radian)
	{
		return radian/(PI / 180.f);
	}

	/*==============================
	[�T�v]
	�x���@���l���ʓx�@���l�ɕϊ�����
	[����]
	�x���@���l : degree
	[�߂�l]
	�ʓx�@���l : float
	===============================*/
	constexpr float convertToRadian(float degree)
	{
		return degree*(PI / 180.f);
	}


	cocos2d::Vec2 convertToDirection(float angle);
};