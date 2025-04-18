#pragma once
#include <vector>
using::std::vector; 
#include "windows.h"
#include "Texture.h"

// ������ �ð�. �������� � ��ȣ�� ������ ������. 
// ������ ���� �������� �������� Ȯ���ϰ�, � ������ ���ؼ� ������ ������. 
// ���� ���� ������ �ҷ��� �迭�� �����ϰ�, 
// �迭�� ������ �������� �ݺ����� ���ؼ� �����ϰ� �ҷ��´�. 

enum AnimState
{
	jumpAtt,
	attack, 
	Run 
};

const char* SpritePath(AnimState curAState) // ������ �ִϸ��̼� ���¸� �޾Ƽ� ������ �ִϸ��̼� ���¿� �´� �ּҸ� ��ȯ 
{
	switch (curAState)
	{
	case jumpAtt: 
		break; 
	case attack : 
		break; 
	case Run : 
		break; 
	}
}
 
class Animation
{
private : 
	vector<AnimState>		 AnimFrame;		// ��� �ִϸ��̼� �������� ������ ���� 
	int 					 cur_Anim;		// ������ �ִϸ��̼� ������ 
	float					 DurtionTime;	// �ִϸ��̼� ������ ���� �ð� 

public : 
	Animation(); 
	~Animation(); 

	void Intialize(AnimState& cur_anim);	 // ������ �ִϸ��̼ǿ� ���� �̹������� ���Ϳ� �����Ѵ�. 
	void Update();							 // ���� �ִϸ��̼��� ������. ������ �ð��� ���� Ű���� ��ǲ ������ ���� ����� �غ� �Ѵ�. 
	void Render();							 // ���� �ִϸ��̼��� ������ ���¿� ���� �ִϸ��̼� ��� 

	void CreateAnim();  // �ִϸ��̼��� ���� �Լ�. ������ ������ ���¿� �´� �����ӿ� �� �̹������� ����� AnimFrame���� �̹����� �޾ƿͼ� �ݺ����� ���ؼ� ���� 

	// ������ �ִϸ��̼� ������ ���� get, set
	//AnimState* GetcurAnimState() { return cur_Anim; };
	//AnimState* SetcurAnimState(AnimState* AState) { return cur_Anim = AState; };
};


