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
{// GDI+ �ʱ�ȭ
	
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&g_GdiPlusToken, &gsi, nullptr);
	g_pBackBufferGraphics = Gdiplus::Graphics::FromHDC(backBufferDC);

	currentAnimState = RUN;
}

void render::Update(HWND hWnd)// ������ ���� ID �� �޾ƿ��� �ڵ�
{ 
	ResourcePath(); // ���� �ִϸ��̼� ���¿� ���� ��ΰ� ��ȯ. 

	if (g_pImageBitmap->GetLastStatus() != Gdiplus::Ok)
	{
		MessageBox(hWnd, L"PNG ���� �ε� ����", L"����", MB_ICONERROR);
		PostQuitMessage(0);
	}

	if (Input::IsKeyDown(VK_LEFT))
	{
		// �̵�
		// ���� ������ �ִϸ��̼��� �÷��� �Ѵ�. 
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
	// GDI+ ����
	delete g_pImageBitmap;
	delete g_pBackBufferGraphics;
	Gdiplus::GdiplusShutdown(g_GdiPlusToken);

	DeleteObject(g_BackBufferBitmap);
	DeleteDC(backBufferDC);

	ReleaseDC(hWnd, FrontBufferDC);
}


