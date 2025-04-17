#pragma once
#include <windows.h>
#include "gdiplus.h"
#include <string> 
using std::wstring; 
using std::string; 
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "Msimg32.lib")

extern void PrintLastErrorMessage();

extern int g_width;
extern int g_height;
class Resource
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


public : 
	void Render();
	//void Loadimage(); 
	
	/*void Loadimage()
	{
		WCHAR path[MAX_PATH];
		GetCurrentDirectoryW(MAX_PATH, path);
		wcscat_s(path, L"\\Resources\\elf32.png");
		MessageBoxW(hWnd_, path, L"실제 시도하는 경로", MB_OK);

		ImageBitmap = new Gdiplus::Bitmap(path);
		if (ImageBitmap->GetLastStatus() != Gdiplus::Ok)
		{
			MessageBoxW(hWnd_, path, L"이미지 로드 실패 경로", MB_ICONERROR);
			PostQuitMessage(0);
		}
	};*/
	Resource(HWND hWnd);
	~Resource(); 


	// 비트맵 이미지 가로 길이 세로 길이 캡슐화 
	UINT GetImgwidth() { return ImageBitmap->GetWidth(); }
	UINT GetImgHeight() { return ImageBitmap->GetHeight(); }

	void SetImgWidth(UINT bitmapwidth) {
		int Imgwidth = ImageBitmap->GetWidth();
		Imgwidth = bitmapwidth;
	}
	void SetImgHeight(UINT bitmapheigth) {
		int Imgheight = ImageBitmap->GetHeight();
		Imgheight = bitmapheigth;
	}

};

