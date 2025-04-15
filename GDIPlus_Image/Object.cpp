#include "Object.h"

void Object::Render(HDC _DC)
{
	Rectangle(g_BackBufferDC, -1, -1, m_pPos.x + 1, m_pPos.y + 1);

	// ±×¸®±â 
	Rectangle(_DC, m_pPos.x - m_pPos.x / 2,
		m_pPos.y - m_pPos.y / 2,
		m_pPos.x + m_pPos.x / 2,
		m_pPos.y + m_pPos.y / 2);

	BitBlt(m_DC, 0, 0, m_ptResolution.x, m_ptResolution.y, g_BackBufferDC, 0, 0, SRCCOPY);
}

Object::Object() : m_pPos{}, m_pScale{}
{
}

Object::~Object()
{
}
