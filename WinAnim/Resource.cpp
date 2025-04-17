#include "Resource.h"



Resource::Resource(HWND hWnd) : hWnd_(hWnd)
{
	RECT rc;
	GetClientRect(hWnd_, &rc);
	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;

	////////Renderer::Initialize
// �´� DC�� ������ ��, ������ ���� 
	FrontBufferDC = GetDC(hWnd_); //������ Ŭ���̾�Ʈ ������ DeviceContext���
	BackBufferDC = CreateCompatibleDC(FrontBufferDC); // ȣȯ�Ǵ� DeviceContext ����
	// DeviceContext ���� �� HBitmap ����
	ImageDC = CreateCompatibleDC(FrontBufferDC); // ȣȯ�Ǵ� DeviceContext ����

	HBITMAP hImageBitmap = (HBITMAP)LoadImage(
		NULL,						// �ν��Ͻ� �ڵ� (�����̹Ƿ� NULL)
		L"../Resource/elf24.bmp",   // BMP ���� ���
		IMAGE_BITMAP,				// ��Ʈ�� �ε�
		0, 0,						// ũ�� �ڵ� (���� ũ��)
		LR_LOADFROMFILE				// �ܺ� ���Ͽ��� �ε�
	);

	
	GetObject(hImageBitmap, sizeof(BITMAP), &bmpInfo);


	if (!hImageBitmap)
		PrintLastErrorMessage();
		
	SelectObject(ImageDC, hImageBitmap);

}

Resource::~Resource()
{
	// �� �� �͵� ����. 
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
		// ���ʿ� �׸���? 
		// DC �ĸ� ������ ���ʿ� �׷����´�. // ���� ���� �׸��� ����. 
	PatBlt(BackBufferDC, 0, 0, g_width, g_height, BLACKNESS);

	// Render()
	// ��ü �̹��� �״�� �����ϱ�
	BitBlt(BackBufferDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, ImageDC, 0, 0, SRCCOPY);

	////Ư�� �÷�(�÷�Ű)�� �����ϰ� �׸���
	//TransparentBlt(BackBufferDC, bmpInfo.bmWidth, 0, bmpInfo.bmWidth, bmpInfo.bmHeight,
	//	ImageDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight,
	//	RGB(255, 255, 255));	// Msimg32.lib ��ũ �ʿ�

	// Renderer::EndDraw()
	// DC ���� ���۷� �����ͼ� �׸���. 
	BitBlt(FrontBufferDC, 0, 0, g_width, g_height, BackBufferDC, 0, 0, SRCCOPY);
}






