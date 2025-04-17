#include "Resource.h"



Resource::Resource(HWND hWnd) : hWnd_(hWnd)
{
	RECT rc;
	GetClientRect(hWnd_, &rc);
	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;

	////////Renderer::Initialize
// 맞는 DC를 가져온 후, 버퍼의 생성 
	FrontBufferDC = GetDC(hWnd_); //윈도우 클라이언트 영역의 DeviceContext얻기
	BackBufferDC = CreateCompatibleDC(FrontBufferDC); // 호환되는 DeviceContext 생성
	// DeviceContext 생성 및 HBitmap 연결
	ImageDC = CreateCompatibleDC(FrontBufferDC); // 호환되는 DeviceContext 생성

	HBITMAP hImageBitmap = (HBITMAP)LoadImage(
		NULL,						// 인스턴스 핸들 (파일이므로 NULL)
		L"../Resource/elf24.bmp",   // BMP 파일 경로
		IMAGE_BITMAP,				// 비트맵 로드
		0, 0,						// 크기 자동 (원본 크기)
		LR_LOADFROMFILE				// 외부 파일에서 로드
	);

	
	GetObject(hImageBitmap, sizeof(BITMAP), &bmpInfo);


	if (!hImageBitmap)
		PrintLastErrorMessage();
		
	SelectObject(ImageDC, hImageBitmap);

}

Resource::~Resource()
{
	// 다 쓴 것들 삭제. 
	DeleteObject(HBackBufferBitmap);
	DeleteDC(ImageDC);

	// Renderer::Uninitialize
	DeleteObject(HBackBufferBitmap);
	DeleteDC(BackBufferDC);
	ReleaseDC(hWnd_, FrontBufferDC);
}


void Resource::Render()
{	
	// Renderer::BeginDraw()
		// 앞쪽에 그리다? 
		// DC 후면 버퍼의 앞쪽에 그려놓는다. // 더블 버퍼 그리기 연산. 
	PatBlt(BackBufferDC, 0, 0, g_width, g_height, BLACKNESS);

	// Render()
	// 전체 이미지 그대로 복사하기
	BitBlt(BackBufferDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, ImageDC, 0, 0, SRCCOPY);

	////특정 컬러(컬러키)를 제외하고 그리기
	//TransparentBlt(BackBufferDC, bmpInfo.bmWidth, 0, bmpInfo.bmWidth, bmpInfo.bmHeight,
	//	ImageDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight,
	//	RGB(255, 255, 255));	// Msimg32.lib 링크 필요

	// Renderer::EndDraw()
	// DC 전면 버퍼로 가져와서 그린다. 
	BitBlt(FrontBufferDC, 0, 0, g_width, g_height, BackBufferDC, 0, 0, SRCCOPY);
}






