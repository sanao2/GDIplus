#include "Animation.h"


Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::Intialize(AnimState& cur_anim) // 현재의 애니메이션에 따른 이미지들을 벡터에 저장한다. 
{
	if (cur_anim == NULL) return; 

	for (int animIndex = 0; animIndex < 3; ++animIndex)
	{
		AnimFrame.push_back(cur_anim);
	}

}
void Animation::Update()
{
	float FrameDeltaTime = FrameDeltaTime + Time::GetDeltaTime();  // 프레임 실시간 재생 시간 

	if (FrameDeltaTime - DurtionTime >= 100)
	{
		cur_Anim = (cur_Anim + 1) % AnimFrame.size();
		DurtionTime = FrameDeltaTime;
	}
}

