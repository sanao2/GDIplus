#include "Player.h"



void Player::Initialize(HWND hWnd)
{
	m_DC = GetDC(hWnd);
}

void Player::playerRender()
{	
	

	Object* player = new Player;
	player->SetPos(Vector2(640.f, 384.f));
	player->SetScale(Vector2(100.f,100.f));
	
	Render(m_DC); 
}

Player::~Player()
{
	DeleteDC(m_DC); 
}
