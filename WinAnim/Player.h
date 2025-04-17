#pragma once
#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#include "Resource.h"

extern HWND g_hWnd; 

extern int g_width;
extern int g_height;

class Player
{
private:
	HWND m_hWnd; 
	HDC  drawDC;	// 메인 윈도우에 그릴 DC 

	POINT playerPos; 
	POINT playerScale;

public : 
	int Init(HWND hWnd, POINT Position);
	void RectRender(); 

	Player();
	~Player(); 
};
