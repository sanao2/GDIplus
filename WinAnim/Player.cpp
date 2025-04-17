#include "Player.h"



Player::Player() : m_hWnd(0), drawDC(0), playerPos{0,0}, playerScale{100,100}
{
	Init(g_hWnd, playerPos);
}

Player::~Player()
{
	ReleaseDC(g_hWnd, drawDC);
}

int Player::Init(HWND hWnd, POINT Resolution)
{
	g_hWnd = m_hWnd;
	drawDC = GetDC(g_hWnd);

	// 원하는 크기가 조정되어 리턴
	RECT rcClient = { 0, 0, (LONG)g_width, (LONG)g_height };  // 새로운 콘솔창 해상도 크기 
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);  // 그릴 Rect 모양을 받아서, 
	//그릴 스타일을 정하고, 메뉴가 있느냐 를 체크한다.


	playerPos = POINT{ Resolution.x, Resolution.y };

	return S_OK;
}
void Player::RectRender()
{


	Rectangle(drawDC, 10, 10, 110, 110);
}