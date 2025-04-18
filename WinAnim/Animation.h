#pragma once
#include <vector>
using::std::vector; 
#include "windows.h"
#include "Texture.h"

// 프레임 시간. 프레임을 어떤 신호로 변경할 것인지. 
// 프레임 현재 프레임이 무엇인지 확인하고, 어떤 조건을 통해서 변경할 것인지. 
// 여러 장의 사진을 불러와 배열에 저장하고, 
// 배열에 저장한 사진들을 반복문을 통해서 저장하고 불러온다. 

enum AnimState
{
	jumpAtt,
	attack, 
	Run 
};

const char* SpritePath(AnimState curAState) // 현재의 애니메이션 상태를 받아서 현재의 애니메이션 상태에 맞는 주소를 반환 
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
	vector<AnimState>		 AnimFrame;		// 모든 애니메이션 프레임을 저장할 벡터 
	int 					 cur_Anim;		// 현재의 애니메이션 프레임 
	float					 DurtionTime;	// 애니메이션 프레임 지속 시간 

public : 
	Animation(); 
	~Animation(); 

	void Intialize(AnimState& cur_anim);	 // 현재의 애니메이션에 따른 이미지들을 벡터에 저장한다. 
	void Update();							 // 현재 애니메이션의 변경점. 프레임 시간에 따라서 키보드 인풋 정보에 따라서 출력할 준비를 한다. 
	void Render();							 // 현재 애니메이션의 프레임 상태에 따라서 애니메이션 출력 

	void CreateAnim();  // 애니메이션을 만들 함수. 현재의 프레임 상태에 맞는 프레임에 들어갈 이미지들이 저장된 AnimFrame에서 이미지를 받아와서 반복문을 통해서 저장 

	// 현재의 애니메이션 프레임 상태 get, set
	//AnimState* GetcurAnimState() { return cur_Anim; };
	//AnimState* SetcurAnimState(AnimState* AState) { return cur_Anim = AState; };
};


