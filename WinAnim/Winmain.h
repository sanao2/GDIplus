#pragma once
#include <windows.h>
#include <stdio.h>

LPCTSTR g_title = TEXT("������ Ÿ��Ʋ�ٿ� ǥ���� ���ڿ�");
LPCTSTR g_szClassName = TEXT("������ Ŭ���� �̸�");

//�ػ� ũ�� �⺻ ���� 
int g_width = 1024;
int g_height = 768;

HWND g_hWnd;				// ������ â ���̵� �ޱ�
HDC g_FrontBufferDC;		// �ո� DC
HDC g_BackBufferDC;			// �޸� DC
HBITMAP g_BackBufferBitmap; // ��Ʈ�� �ĸ� ���� 

void Resolution(HINSTANCE hInstance, int nCmdShow, int g_width, int g_height)
{
	// ���ϴ� ũ�Ⱑ �����Ǿ� ����
	RECT rcClient = { 0, 0, g_width, g_height };  // ���ο� �ܼ�â �ػ� ũ�� 
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);  // �׸� Rect ����� �޾Ƽ�, 
	//�׸� ��Ÿ���� ���ϰ�, �޴��� �ִ��� �� üũ�Ѵ�.

//����
// ������ ���̵� Ÿ������ �ܼ�â�� ���� �Ѵ�. 
	HWND hwnd = CreateWindow(
		g_szClassName,		 // ������ Ŭ���� �̸� 
		g_title,			 // ������ â ���� 
		WS_OVERLAPPEDWINDOW, // ������ ��Ÿ�� 
		CW_USEDEFAULT,		 // ������ ����(X) ���� 
		CW_USEDEFAULT,		 // ������ ����(Y) ���� 
		//Ŭ���̾�Ʈ â ũ�� �߾� ���ϱ� 
		rcClient.right - rcClient.left,
		rcClient.bottom - rcClient.top,
		NULL, NULL, hInstance, NULL);

	// ������ â�� �����ֱ�. 
	// ������ â ǥ�� ���¸� �����Ѵ�. (������ �μ� : SW_ ���) 
	// â�� �������� �����ٸ� true, �������� ������ �־��ٸ� fasle.��ȯ 
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

}