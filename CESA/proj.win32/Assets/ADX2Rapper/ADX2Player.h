/*////////////////////////////////////////////////////////
[�t�@�C����]
ADX2Player.h
[�T�v]
cri_adx2le CriAtomExPlayer���b�p�[
[�쐬��]
�ēc����
[�X�V��]
2016/05/06
////////////////////////////////////////////////////////*/
#pragma once

#include"ADX2Manager.h"

class ADX2Player
{
private:
	// �v���C���[�n���h��
	CriAtomExPlayerHn m_playerHandle;

public:
	/*==============================
	[�T�v]
	�R���X�g���N�^
	[����]
	�L���[�n���h�� : CriAtomExAcbHn
	�L���[ID : CriAtomExCueId
	[�߂�l]
	�Ȃ�
	===============================*/
	ADX2Player(CriAtomExAcbHn acbHandle, CriAtomExCueId cueId);


	/*==============================
	[�T�v]
	�f�X�g���N�^
	[����]
	�Ȃ�
	[�߂�l]
	�Ȃ�
	===============================*/
	~ADX2Player();


	/*==============================
	[�T�v]
	�Đ��J�n
	[����]
	�Ȃ�
	[�߂�l]
	�v���C�o�b�NID : CriAtomExPlaybackId
	===============================*/
	CriAtomExPlaybackId start();
	

	/*==============================
	[�T�v]
	�Đ�����
	[����]
	�Ȃ�
	[�߂�l]
	�v���C�o�b�NID : CriAtomExPlaybackId
	===============================*/
	CriAtomExPlaybackId prepare();

	/*==============================
	[�T�v]
	�Đ���~
	[����]
	�Ȃ�
	[�߂�l]
	�Ȃ�
	===============================*/
	void stop();

	void pause();
	void resume();

	/*==============================
	[�T�v]
	�Đ����Ԃ̎w��
	[����]
	�Đ�����(�~���b) : CriSint64
	[�߂�l]
	�Ȃ�
	===============================*/
	void setStartTime(CriSint64 startTime);

	/*==============================
	[�T�v]
	�Đ����Ԃ̎擾
	[����]
	�Ȃ�
	[�߂�l]
	�Đ�����(�~���b) : CriSint64
	===============================*/
	CriSint64 getTime()const;
	
	/*==============================
	[�T�v]
	�v���C���[�n���h���̎擾
	[����]
	�Ȃ�
	[�߂�l]
	�v���C���[�n���h�� : CriAtomExPlayerHn
	===============================*/
	CriAtomExPlayerHn getPlayerHandle()const;

	/*==============================
	[�T�v]
	�X�e�[�^�X�̎擾
	[����]
	�Ȃ�
	[�߂�l]
	�X�e�[�^�X : CriAtomExPlayerStatus
	===============================*/
	CriAtomExPlayerStatus getStatus()const;

	
	/*==============================
	[�T�v]
	���ݍĐ��ʒu��ύX����(�V�[�N����)
	[����]
	�Đ��ʒu(�~���b) : CriSint64
	[�߂�l]
	�Ȃ�
	===============================*/
	void seekPlayTime(CriSint64 time);
};