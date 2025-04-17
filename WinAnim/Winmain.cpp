#include "Winmain.h"
#include "Resource.h"
#include "Player.h"
#pragma comment(lib, "Msimg32.lib")	




// �ܼ� �ʱ�ȭ
void InitConsole()
{
	AllocConsole(); // �ܼ��� �����Ѵ�. 
	FILE* fp; // ���� ������. 
	// ������ CONOUT$ �̸����� �б� ���� ����. 
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
	DWORD errorCode = GetLastError(); // ��ȯ�ؾ� �ϴ� ���� �ڵ�. 
	LPVOID lpMsgBuf; // �ý��� �޽��� ���̵� ���� ��� �ǰ�? 

	// ���� �ڵ�, �ý��� �޽����� ����� ���� �� �ִ� ���ڿ��� ��ȯ.
	// �ý��� �޽����� �츮�� ���� �� �ֵ��� ��ȯ. 
	FormatMessageA(
		// �׸� �޽��� �÷��� 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, //�޽��� ���� �÷��� 
		NULL, // �޽��� ���� (NULL �� �ý��� �޽��� ��� 
		errorCode, // ��ȯ�� �����ڵ�
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // �⺻ ���
		(LPSTR)&lpMsgBuf,// ��� �޽����� ������ ���ڿ� ���� 
		0,				 // ������ 
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
// ������ ���ν���. 
//HWND hwnd = ������ ���̵� �ޱ�, UINT msg = �޽���,  
//WPARAM wParam = Ű���� �Է� ����, LPARAM lParam = ���콺 �Է� ���� 
// ���ο��� ���� ���� �޽����� ó���Ѵ�. 
// �׸��� �޽�������, Ű���� �Է� �޽�������, ���콺 �Է� �޽�������, ���� �޽�������.
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)// ���� �޽����� ���� �� ��, ���α׷� ���� 
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT: 
		
		break; 
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

// ���� ������ ���̵�� ���� ������ ���̵�, ����(char) Ÿ���� �׸� ��, 
// �׸��� ��� �׸� �� ����(int) �� �� �Ķ���͸� �޴´�. 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	InitConsole();  // �ܼ� ��� �ʱ�ȭ

	char szPath[MAX_PATH] = { 0, };
	// ���� ���̿� ���� ��θ� �޾Ƽ� ���� �۾� ���丮�� �ҷ��´�. 
	::GetCurrentDirectoryA(MAX_PATH, szPath);
	printf("Current Directory: %s\n", szPath);

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;						// ������ ���ν����� �޾ƿ´�. 
	wc.hInstance = hInstance;						// ������� ���μ����� �޾ƿ´�. 
	wc.lpszClassName = g_szClassName;				// ���̵��� �̸�. 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  // �귯���� ��ȯ�� Window â�� ��׶���(���) �� �޾ƿ´�. 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);		// �⺻ Ŀ�� ���
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);		// �⺻ ������ ���
	RegisterClass(&wc);

	Resolution(hInstance, nCmdShow, g_width, g_height);

	Resource* Rs = new Resource(g_hWnd); 
	//Player* player = new Player();


	// �޸� ��������
	// HDC => DC�� �ڵ� ���̵��� ���ο� ���� ���̸� �޾ƿ� ������ ����. 
	g_BackBufferBitmap = CreateCompatibleBitmap(g_FrontBufferDC, g_width, g_height);
	SelectObject(g_BackBufferDC, g_BackBufferBitmap); // g_BackBufferDC�� �޸𸮿��� ����



	MSG msg;
	while (true)
	{
		//PeekMassage =>  �޽����� ���ĺ���. �޽����� ���� ���ο� ���� ��ȯ �� �����ϴ�. true�� �� ������ �޽����� ����.
		// ���ǹ��� ��� �����ϴ�. 
		// ������ ������ UNIT wRemoveMsg => �޽��� ť���� Ȯ���� �޽����� ������ �ÿ� ���� ���� ���� �Ķ����.
		// (PM_REMOVE = ����) 
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);		// �޽����� �޾Ƽ� Ű���� �޽����� ���� �޽����� ��ȯ. -> Ű���� �Է¹��� �޽����� ���� �޽����� ��ȯ??
			DispatchMessage(&msg);		// �޽����� ������ ���ν��� (WndProc) ���� ���� 
		}
		//player->RectRender();
		Rs->Render(); 
	}

	delete Rs;
	
	//////////////////////////////////////////////////////////////////////////

	UninitConsole();  // �ܼ� ��� ����
	return (int)msg.wParam;
}
