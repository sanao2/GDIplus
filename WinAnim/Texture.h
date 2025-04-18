#pragma once
#include <windows.h>
#include "Animation.h"
#include "gdiplus.h"
#include "Time.h"
#include <string> 
using std::wstring; 
using std::string; 
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "Msimg32.lib")

extern void PrintLastErrorMessage();

extern int g_width;
extern int g_height;
class Texture
{
private : 

	HWND hWnd_;
	HDC FrontBufferDC;
	HDC BackBufferDC;
	HDC ImageDC;

	HBITMAP HBackBufferBitmap;

	// GDI+ 초기화용
	ULONG_PTR g_GdiPlusToken;
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::Bitmap* ImageBitmap;
	Gdiplus::Graphics* BackBufferGraphics;

	BITMAP bmpInfo; // 내부에 크기 정보가 있다.

	char* curRectivePath; // 앞으로 불러오게 될 상대 경로 


	UINT ImgWidth = 0; 
	UINT ImgHeight = 0; 

public : 
	void Update();
	void GDIRender();
	void GDIplusRender(); 

	void GDILoadimage(); 
	void GDIplusLoadImage(const wchar_t* AnimPath);
	
	
	Texture(HWND hWnd);
	~Texture(); 

	// 현재 상대 경로 get, set 
	wchar_t* GetPath(AnimState AState)
	{
		return curRectivePath = SpritePath(AState);
	}
	void SetPath(wchar_t* RectivePath)
	{
		curRectivePath = RectivePath;
	}

	// 비트맵 이미지 가로 길이 세로 길이 캡슐화 
	UINT GetImgWidth() { return ImgWidth = ImageBitmap->GetWidth(); }
	UINT GetImgHeight() { return ImgHeight = ImageBitmap->GetHeight(); }
	
	void SetImgWidth(UINT bitmapwidth) {
		ImgWidth = bitmapwidth;
	}
	void SetImgHeight(UINT bitmapheigth) {
		ImgHeight = bitmapheigth;
	}

};

