#include"DxLib.h"
#include "StraightBullets.h"
#include"GameMainScene.h"

//Ç‹Ç¡Ç∑ÇÆîÚÇ‘íe

StraightBullets::StraightBullets(T_Location location, T_Location speed)
	:BulletsBase(location, 5.f, 1, speed)
{

}

void StraightBullets::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);

}

void StraightBullets::Draw()
{
	int ImageBullet = LoadGraph("images/Bullet.png");

	DrawGraph(GetLocation().x - 10, GetLocation().y - 35, ImageBullet, FALSE);
	//DrawCircle(GetLocation().x, GetLocation().y -15, GetRadius(), GetColor(0, 255, 0));
}

//âÊñ äOÇ…èoÇΩÇÁíeÇè¡Ç∑
bool StraightBullets::isScreenOut()
{
	bool ret = ((GetLocation().y + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (HEIGHT <= (GetLocation().y - GetRadius()));
	return ret;
}