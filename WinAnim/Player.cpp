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

	// ���ϴ� ũ�Ⱑ �����Ǿ� ����
	RECT rcClient = { 0, 0, (LONG)g_width, (LONG)g_height };  // ���ο� �ܼ�â �ػ� ũ�� 
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);  // �׸� Rect ����� �޾Ƽ�, 
	//�׸� ��Ÿ���� ���ϰ�, �޴��� �ִ��� �� üũ�Ѵ�.


	playerPos = POINT{ Resolution.x, Resolution.y };

	return S_OK;
}
void Player::RectRender()
{


	Rectangle(drawDC, 10, 10, 110, 110);
}