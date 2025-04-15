#pragma once
#include "pch.h"
#include "Render.h"
#include "Object.h"
#include "player.h"


class render; 

extern HWND g_hWnd;

Object obj; 
render rd;

class core
{
private : 
	HDC  m_DC;				//메인에 Draw 할 DC 
	HWND g_hWnd;
	HDC g_FrontBufferDC;
	HDC g_BackBufferDC;
	LPCTSTR g_szClassName = TEXT("윈도우 클래스 이름");
public : 
	POINT m_ptResolution;
	int Intialize(HWND hWnd, POINT _ptResolution);
	void Loop(); 
	void Update(); 
	void Render();

public : 
	POINT GetResolution() { return m_ptResolution; }
	POINT SetResolution(POINT ResolutionPos) { return m_ptResolution = ResolutionPos; }

	core();
	~core();

	friend class render; 
};

