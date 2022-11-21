#include"DxLib.h"
#include "SpiralBullets.h"
#include"GameMainScene.h"

SpiralBullets::SpiralBullets(T_Location location, T_Location speed)
	:BulletsBase(location, 5.f, 1, speed)
{

}

void SpiralBullets::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);
}

void SpiralBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 170, 220));
}

bool SpiralBullets::isScreenOut()
{
	bool ret = ((GetLocation().y + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (WINDOW_HEIGHT <= (GetLocation().y - GetRadius()));
	return ret;
}