#pragma once
#include <windows.h>
#include <stdio.h>

LPCTSTR g_title = TEXT("������ Ÿ��Ʋ�ٿ� ǥ���� ���ڿ�");
LPCTSTR g_szClassName = TEXT("������ Ŭ���� �̸�");

//�ػ� ũ�� �⺻ ���� 
int g_width = 1024;
int g_height = 768;
POINT WindPos = { 1024, 768 };

HWND g_hWnd;				// ������ â ���̵� �ޱ�
HDC g_FrontBufferDC;		// �ո� DC
HDC g_BackBufferDC;			// �޸� DC


void Resolution(HINSTANCE hInstance, int nCmdShow, int g_width, int g_height);
