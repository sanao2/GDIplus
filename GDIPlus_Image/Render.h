#pragma once
#include "pch.h"


extern int g_width;
extern int g_height;

class render
{
private : 
	
	HDC				   backBufferDC;		  // 후면 DC
	HDC				   FrontBufferDC;		  // 앞면 DC
	ULONG_PTR		   g_GdiPlusToken;		  // Gdi+ 용 토큰
	HBITMAP			   g_BackBufferBitmap;    // 이미지의 비트맵 핸들 
	Gdiplus::Bitmap*   g_pImageBitmap;	      // 불러올 이미지 
	Gdiplus::Graphics* g_pBackBufferGraphics;
	char			   currentAnimState;	  //현재의 애니메이션 상태 
	
public : 
	void Initialize(); 
	void Update(HWND hWnd);
	void Render();
	void Relese(HWND hWnd);

	char GetAnimState() { return currentAnimState;  }
	char SetAnimState(char curAnimState) { return currentAnimState = curAnimState;  }

	const char* ResourcePath();
};

