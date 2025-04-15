#include "Render.h"


enum AnimState
{
	JUMPATT,  
	RUN,
	ATTACK 
} AnimSt;

const char* render::ResourcePath()
{
	switch (currentAnimState)
	{
	case JUMPATT:
		const char* filePath = "\Resource\jumpattack.txt";
		return filePath;
		break;
	case RUN:
		const char* filePath = "\Resource\RUN.txt"; 
		return filePath;
		break;
	case ATTACK:
		const char* filePath = "\Resource\attack.txt";
		return filePath;
		break;
	}
}

void render::Initialize()
{// GDI+ 초기화
	
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&g_GdiPlusToken, &gsi, nullptr);
	g_pBackBufferGraphics = Gdiplus::Graphics::FromHDC(backBufferDC);

	currentAnimState = RUN;
}

void render::Update(HWND hWnd)// 윈도우 메인 ID 값 받아오는 핸들
{ 
	ResourcePath(); // 현재 애니메이션 상태에 따라서 경로가 반환. 

	if (g_pImageBitmap->GetLastStatus() != Gdiplus::Ok)
	{
		MessageBox(hWnd, L"PNG 파일 로드 실패", L"오류", MB_ICONERROR);
		PostQuitMessage(0);
	}

	if (Input::IsKeyDown(VK_LEFT))
	{
		// 이동
		// 눌릴 때마다 애니메이션을 플레이 한다. 
	}
	

}

void render::Render()
{
	//g_pBackBufferGraphics->DrawImage(g_pImageBitmap, 0, 0, witdh, height);
	// Renderer::BeginDraw()
	PatBlt(backBufferDC, 0, 0, g_width, g_height, BLACKNESS);

	// Render()
	g_pBackBufferGraphics->DrawImage(g_pImageBitmap, 0, 0);

	// Renderer::EndDraw()
	BitBlt(FrontBufferDC, 0, 0, g_width, g_height, backBufferDC, 0, 0, SRCCOPY);
}

void render::Relese(HWND hWnd)
{
	// GDI+ 해제
	delete g_pImageBitmap;
	delete g_pBackBufferGraphics;
	Gdiplus::GdiplusShutdown(g_GdiPlusToken);

	DeleteObject(g_BackBufferBitmap);
	DeleteDC(backBufferDC);

	ReleaseDC(hWnd, FrontBufferDC);
}


