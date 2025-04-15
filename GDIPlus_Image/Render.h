#pragma once
#include "pch.h"


extern int g_width;
extern int g_height;

class render
{
private : 
	
	HDC				   backBufferDC;		  // �ĸ� DC
	HDC				   FrontBufferDC;		  // �ո� DC
	ULONG_PTR		   g_GdiPlusToken;		  // Gdi+ �� ��ū
	HBITMAP			   g_BackBufferBitmap;    // �̹����� ��Ʈ�� �ڵ� 
	Gdiplus::Bitmap*   g_pImageBitmap;	      // �ҷ��� �̹��� 
	Gdiplus::Graphics* g_pBackBufferGraphics;
	char			   currentAnimState;	  //������ �ִϸ��̼� ���� 
	
public : 
	void Initialize(); 
	void Update(HWND hWnd);
	void Render();
	void Relese(HWND hWnd);

	char GetAnimState() { return currentAnimState;  }
	char SetAnimState(char curAnimState) { return currentAnimState = curAnimState;  }

	const char* ResourcePath();
};

