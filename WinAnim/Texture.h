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

	// GDI+ �ʱ�ȭ��
	ULONG_PTR g_GdiPlusToken;
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::Bitmap* ImageBitmap;
	Gdiplus::Graphics* BackBufferGraphics;

	BITMAP bmpInfo; // ���ο� ũ�� ������ �ִ�.

	string* curRectivePath; // ������ �ҷ����� �� ��� ��� 

	UINT ImgWidth = 0; 
	UINT ImgHeight = 0; 

public : 
	void Update();
	void GDIRender();
	void GDIplusRender(); 

	void GDILoadimage(); 
	void GDIplusLoadImage(); 
	
	
	Texture(HWND hWnd);
	~Texture(); 

	UINT GetWidth() {
		return ImageBitmap->GetWidth(); 
	}

	// ��Ʈ�� �̹��� ���� ���� ���� ���� ĸ��ȭ 
	UINT GetImgWidth() { return ImgWidth = ImageBitmap->GetWidth(); }
	UINT GetImgHeight() { return ImgHeight = ImageBitmap->GetHeight(); }
	
	void SetImgWidth(UINT bitmapwidth) {
		ImgWidth = bitmapwidth;
	}
	void SetImgHeight(UINT bitmapheigth) {
		ImgHeight = bitmapheigth;
	}

};

