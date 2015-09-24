#include "stdafx.h"
#include <windows.h>
#include "KeyManage.h"

/*
const int INPUT_MOUSE = 0;                  // �}�E�X�C�x���g
const int INPUT_KEYBOARD = 1;               // �L�[�{�[�h�C�x���g
const int INPUT_HARDWARE = 2;               // �n�[�h�E�F�A�C�x���g

const int MOUSEEVENTF_MOVE = 0x1;           // �}�E�X���ړ�����
const int MOUSEEVENTF_ABSOLUTE = 0x8000;    // ��΍��W�w��
const int MOUSEEVENTF_LEFTDOWN = 0x2;       // ���@�{�^��������
const int MOUSEEVENTF_LEFTUP = 0x4;         // ���@�{�^���𗣂�
const int MOUSEEVENTF_RIGHTDOWN = 0x8;      // �E�@�{�^��������
const int MOUSEEVENTF_RIGHTUP = 0x10;       // �E�@�{�^���𗣂�
const int MOUSEEVENTF_MIDDLEDOWN = 0x20;    // �����{�^��������
const int MOUSEEVENTF_MIDDLEUP = 0x40;      // �����{�^���𗣂�
const int MOUSEEVENTF_WHEEL = 0x800;        // �z�C�[������]����
const int WHEEL_DELTA = 120;                // �z�C�[����]�l

const int KEYEVENTF_KEYDOWN = 0x0;          // �L�[������
const int KEYEVENTF_KEYUP = 0x2;            // �L�[�𗣂�
const int KEYEVENTF_EXTENDEDKEY = 0x1;      // �g���R�[�h
const int KEYEVENTF_SCANCODE = 0x0008;
const int VK_SHIFT = 0x10;                  // SHIFT�L�[
const int VK_RETURN = 0x0D;                 // ENTER
const int VK_UP = 0x26;                     // UP
const int VK_RIGHT = 0x27;                  // RIGHT
const int VK_LEFT = 0x25;                   // LEFT
const int VK_DOWN = 0x28;                   // DOWN
*/


void SendKey(short keycode)
{
	Sleep(300);
	
	
	int num = 2;
	INPUT inp[2];

	inp[0].type = INPUT_KEYBOARD;
	inp[0].ki.wVk = keycode;
	inp[0].ki.wScan = (short)MapVirtualKey(inp[0].ki.wVk, 0);
	inp[0].ki.dwFlags = KEYEVENTF_SCANCODE;
	inp[0].ki.dwExtraInfo = GetMessageExtraInfo();
	inp[0].ki.time = 0;

	SendInput(1, &inp[0], sizeof(INPUT));

	Sleep(200);

	inp[1].type = INPUT_KEYBOARD;
	inp[1].ki.wVk = keycode;
	inp[1].ki.wScan = (short)MapVirtualKey(inp[1].ki.wVk, 0);
	inp[1].ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	inp[1].ki.dwExtraInfo = GetMessageExtraInfo();
	inp[1].ki.time = 0;

	SendInput(1, &inp[1], sizeof(INPUT));
}

void TouhouAILogic::KeyManage::SendUp()
{
	SendKey(VK_UP);
}