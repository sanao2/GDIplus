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

	// GDI+ �ʱ�ȭ��
	ULONG_PTR g_GdiPlusToken;
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::Bitmap* ImageBitmap;
	Gdiplus::Graphics* BackBufferGraphics;
	BITMAP bmpInfo; // ���ο� ũ�� ������ �ִ�.


public : 
	void Render();
	//void Loadimage(); 
	
	/*void Loadimage()
	{
		WCHAR path[MAX_PATH];
		GetCurrentDirectoryW(MAX_PATH, path);
		wcscat_s(path, L"\\Resources\\elf32.png");
		MessageBoxW(hWnd_, path, L"���� �õ��ϴ� ���", MB_OK);

		ImageBitmap = new Gdiplus::Bitmap(path);
		if (ImageBitmap->GetLastStatus() != Gdiplus::Ok)
		{
			MessageBoxW(hWnd_, path, L"�̹��� �ε� ���� ���", MB_ICONERROR);
			PostQuitMessage(0);
		}
	};*/
	Resource(HWND hWnd);
	~Resource(); 


	// ��Ʈ�� �̹��� ���� ���� ���� ���� ĸ��ȭ 
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

