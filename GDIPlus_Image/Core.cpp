#include "Core.h"



int core::Intialize(HWND hWnd, POINT _ptResolution)
{
	m_DC = GetDC(hWnd);
	m_ptResolution = _ptResolution;

	// 원하는 크기가 조정되어 리턴
	RECT rcClient = { 0, 0, (LONG)m_ptResolution.x, (LONG)m_ptResolution.y };
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);
	

	//rcClient.right - rcClient.left; // 가로 길이 
	//rcClient.bottom - rcClient.top; // 세로 길이 
	
	//obj.m_pPos = POINT{ m_ptResolution.x / 2, m_ptResolution.y / 2 };
	//obj.m_pScale = POINT{ 100, 100 };
		
	return S_OK;
}

void core::Loop() 
{
	static int callcount = 0; 
	++callcount; 

	static int iPrevCount = GetTickCount();

	int iCurCount = GetTickCount();
	if (GetTickCount() - iPrevCount > 1000)
	{// Loop 가 몇번 반복하는 지 확인
		iPrevCount = iCurCount;
		callcount = 0;  
	}

	Update();

	Render();
}

void core::Update()
{
	Vector2 playerPos = obj.GetPos();

	// 오브젝트들의 좌표 및 변경점 해결 후 렌더링하기 전단계 (키 입력) 
	if (Input::IsKeyDown(VK_LEFT))
	{
		playerPos.x -= 1;
	}
	if (Input::IsKeyDown(VK_RIGHT))
	{
		playerPos.y += 1;
	}
	obj.SetPos(playerPos);
}

void core::Render()
{
	Rectangle(g_BackBufferDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	//그리기 
	Vector2 vPos = obj.GetPos(); 
	Vector2 vScale = obj.GetScale(); 

	Rectangle(g_BackBufferDC, vPos.x - vScale.x / 2.f,
						      vPos.y - vScale.y / 2.f,
						      vPos.x + vScale.x / 2.f,
						      vPos.y + vScale.y / 2.f);

	BitBlt(m_DC, 0, 0, m_ptResolution.x, m_ptResolution.y, g_BackBufferDC, 0, 0, SRCCOPY);
}


core::core() : m_DC(0), m_ptResolution{}, g_hWnd(0)
{
}

core::~core()
{
	ReleaseDC(g_hWnd, m_DC);
}
