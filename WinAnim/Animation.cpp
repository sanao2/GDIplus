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