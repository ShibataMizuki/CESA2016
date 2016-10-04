#pragma once

#include"ADX2Manager.h"
#include"ADX2Player.h"

// ADX2�T�|�[�g�֐�
namespace ADX2Util
{
	/*==============================
	[�T�v]
	�~���b��b�ɕϊ�����
	[����]
	�ϊ�����l(�~���b) : milSec
	[�߂�l]
	�ϊ���̒l(�b) : float
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
