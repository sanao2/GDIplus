#include "Animation.h"


Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::Intialize(AnimState& cur_anim) // ������ �ִϸ��̼ǿ� ���� �̹������� ���Ϳ� �����Ѵ�. 
{
	if (cur_anim == NULL) return; 

	for (int animIndex = 0; animIndex < 3; ++animIndex)
	{
		AnimFrame.push_back(cur_anim);
	}

}
void Animation::Update()
{
	float FrameDeltaTime = FrameDeltaTime + Time::GetDeltaTime();  // ������ �ǽð� ��� �ð� 

	if (FrameDeltaTime - DurtionTime >= 100)
	{
		cur_Anim = (cur_Anim + 1) % AnimFrame.size();
		DurtionTime = FrameDeltaTime;
	}
}

