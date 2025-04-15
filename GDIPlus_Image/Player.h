#pragma once
#include "pch.h"
#include "Object.h"
#include "Core.h"



class Player : public Object
{
private:
	HDC  m_DC;		
	
public : 

	void Initialize(HWND hWnd);
	void playerRender();

	
	~Player() override;


};

