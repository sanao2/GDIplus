#pragma once
#include "pch.h"



class Object
{
private : 
	HDC  m_DC;
	POINT m_ptResolution;
	Vector2  m_pPos; 
	Vector2  m_pScale;
	HDC g_FrontBufferDC;
	HDC g_BackBufferDC;
public : 
	void Render(HDC _DC);

	Vector2 SetPos(Vector2 _vPos) { m_pPos = _vPos; }
	Vector2 SetScale(Vector2 _vScale) { m_pScale = _vScale; }
	Vector2 GetPos() { return m_pPos; }
	Vector2 GetScale() { return m_pScale; }

	Object(); 
	virtual ~Object(); 
};

