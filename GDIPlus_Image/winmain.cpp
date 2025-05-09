#include "pch.h"
#include "Core.h"
LPCTSTR g_szClassName = TEXT("윈도우 클래스 이름");
int g_width = 1024;
int g_height = 768;

HWND g_hWnd;

//HDC g_FrontBufferDC;    // 앞면 DC
//HDC g_BackBufferDC;    // 뒷면 DC

// 콘솔 초기화
void InitConsole()
{
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	SetConsoleTitle(L"윈도우 메시지 콘솔 로그");
	printf("콘솔 로그 시작...\n\n");
}

void UninitConsole()
{
	// 표준 출력 스트림 닫기
	fclose(stdout);
	// 콘솔 해제
	FreeConsole();
}

// WIN32 API 에러 값에 대한 실제 메세지를 출력하는 함수
void PrintLastErrorMessage()
{
	DWORD errorCode = GetLastError();
	LPVOID lpMsgBuf;

	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // 기본 언어
		(LPSTR)&lpMsgBuf,
		0,
		NULL);

	if (lpMsgBuf)
	{
		printf("오류 코드: %lu\n오류 메시지: %s\n", errorCode, (char*)lpMsgBuf);
		LocalFree(lpMsgBuf); // 할당된 버퍼 해제
	}
	else
	{
		printf("오류 코드: %lu (메시지를 찾을 수 없음)\n", errorCode);
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
		//DC를 만들어서 ID를 변환 
	  	HDC hdc = BeginPaint(g_hWnd, &ps);
	  
		// 그리기 종료 
		EndPaint(g_hWnd, &ps);
	  }
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	InitConsole();  // 콘솔 출력 초기화

	char szPath[MAX_PATH] = { 0, };
	::GetCurrentDirectoryA(MAX_PATH, szPath);
	printf("Current Directory: %s\n", szPath);

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = g_szClassName;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// 기본 커서 모양
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// 기본 아이콘 모양
	RegisterClass(&wc);

	core cor;
	cor.Intialize(); 
	// 원하는 크기가 조정되어 리턴
	RECT rcClient = { 0, 0, (LONG)g_width, (LONG)g_height };
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);

	//생성
	HWND hwnd = CreateWindow(
		g_szClassName,
		TEXT("윈도우 타이틀바에 표시할 문자열"),
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

	UninitConsole();  // 콘솔 출력 해제
	return (int)msg.wParam;
}
