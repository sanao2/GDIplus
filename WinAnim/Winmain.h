#pragma once
#include <windows.h>
#include <stdio.h>

LPCTSTR g_title = TEXT("윈도우 타이틀바에 표시할 문자열");
LPCTSTR g_szClassName = TEXT("윈도우 클래스 이름");

//해상도 크기 기본 길이 
int g_width = 1024;
int g_height = 768;
POINT WindPos = { 1024, 768 };

HWND g_hWnd;				// 윈도우 창 아이디 받기
HDC g_FrontBufferDC;		// 앞면 DC
HDC g_BackBufferDC;			// 뒷면 DC


void Resolution(HINSTANCE hInstance, int nCmdShow, int g_width, int g_height);
