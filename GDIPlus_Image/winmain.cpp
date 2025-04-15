#include "pch.h"
#include "Core.h"
LPCTSTR g_szClassName = TEXT("������ Ŭ���� �̸�");
int g_width = 1024;
int g_height = 768;

HWND g_hWnd;

//HDC g_FrontBufferDC;    // �ո� DC
//HDC g_BackBufferDC;    // �޸� DC

// �ܼ� �ʱ�ȭ
void InitConsole()
{
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	SetConsoleTitle(L"������ �޽��� �ܼ� �α�");
	printf("�ܼ� �α� ����...\n\n");
}

void UninitConsole()
{
	// ǥ�� ��� ��Ʈ�� �ݱ�
	fclose(stdout);
	// �ܼ� ����
	FreeConsole();
}

// WIN32 API ���� ���� ���� ���� �޼����� ����ϴ� �Լ�
void PrintLastErrorMessage()
{
	DWORD errorCode = GetLastError();
	LPVOID lpMsgBuf;

	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // �⺻ ���
		(LPSTR)&lpMsgBuf,
		0,
		NULL);

	if (lpMsgBuf)
	{
		printf("���� �ڵ�: %lu\n���� �޽���: %s\n", errorCode, (char*)lpMsgBuf);
		LocalFree(lpMsgBuf); // �Ҵ�� ���� ����
	}
	else
	{
		printf("���� �ڵ�: %lu (�޽����� ã�� �� ����)\n", errorCode);
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT : 
	  {
	  	PAINTSTRUCT ps;
		//DC�� ���� ID�� ��ȯ 
	  	HDC hdc = BeginPaint(g_hWnd, &ps);
	  
		// �׸��� ���� 
		EndPaint(g_hWnd, &ps);
	  }
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	InitConsole();  // �ܼ� ��� �ʱ�ȭ

	char szPath[MAX_PATH] = { 0, };
	::GetCurrentDirectoryA(MAX_PATH, szPath);
	printf("Current Directory: %s\n", szPath);

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = g_szClassName;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// �⺻ Ŀ�� ���
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �⺻ ������ ���
	RegisterClass(&wc);

	core cor;
	cor.Intialize(); 
	// ���ϴ� ũ�Ⱑ �����Ǿ� ����
	RECT rcClient = { 0, 0, (LONG)g_width, (LONG)g_height };
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);

	//����
	HWND hwnd = CreateWindow(
		g_szClassName,
		TEXT("������ Ÿ��Ʋ�ٿ� ǥ���� ���ڿ�"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		rcClient.right - rcClient.left, rcClient.bottom - rcClient.top,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		
	}


	//////////////////////////////////////////////////////////////////////////

	UninitConsole();  // �ܼ� ��� ����
	return (int)msg.wParam;
}
