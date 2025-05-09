#pragma once
#include <windows.h>
#include <gdiplus.h>
#include "Input.h"
#pragma comment(lib, "gdiplus.lib")
#include "Texture.h"

extern HWND g_hWnd; 

extern int g_width;
extern int g_height;

class Player
{
private:
	HWND m_hWnd; 
	HDC  drawDC;	// 메인 윈도우에 그릴 DC 

	POINT playerPos = { 0,0 };
	POINT playerScale;

public : 
	int Init(HWND hWnd, int Rewidth, int Reheight);
	void RectRender(); 

	Player();
	~Player(); 
};
