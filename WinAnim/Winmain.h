#pragma once
#include <windows.h>
#include <stdio.h>

LPCTSTR g_title = TEXT("윈도우 타이틀바에 표시할 문자열");
LPCTSTR g_szClassName = TEXT("윈도우 클래스 이름");

//해상도 크기 기본 길이 
int g_width = 1024;
int g_height = 768;

HWND g_hWnd;				// 윈도우 창 아이디 받기
HDC g_FrontBufferDC;		// 앞면 DC
HDC g_BackBufferDC;			// 뒷면 DC
HBITMAP g_BackBufferBitmap; // 비트맵 후면 버퍼 

void Resolution(HINSTANCE hInstance, int nCmdShow, int g_width, int g_height)
{
	// 원하는 크기가 조정되어 리턴
	RECT rcClient = { 0, 0, g_width, g_height };  // 새로운 콘솔창 해상도 크기 
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);  // 그릴 Rect 모양을 받아서, 
	//그릴 스타일을 정하고, 메뉴가 있느냐 를 체크한다.

//생성
// 윈도우 아이디 타입으로 콘솔창을 생성 한다. 
	HWND hwnd = CreateWindow(
		g_szClassName,		 // 윈도우 클래스 이름 
		g_title,			 // 윈도우 창 제목 
		WS_OVERLAPPEDWINDOW, // 윈도우 스타일 
		CW_USEDEFAULT,		 // 윈도우 가로(X) 길이 
		CW_USEDEFAULT,		 // 윈도우 세로(Y) 길이 
		//클라이언트 창 크기 중앙 구하기 
		rcClient.right - rcClient.left,
		rcClient.bottom - rcClient.top,
		NULL, NULL, hInstance, NULL);

	// 윈도우 창에 보여주기. 
	// 윈도우 창 표시 상태를 변경한다. (마지막 인수 : SW_ 상수) 
	// 창이 이전에도 보였다면 true, 이전에는 숨겨져 있었다면 fasle.반환 
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

}