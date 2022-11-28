#include"DxLib.h"
#include "SpiralBullets.h"
#include"GameMainScene.h"
#include<math.h>

SpiralBullets::SpiralBullets(T_Location location, T_Location speed,float Angle)
	:BulletsBase(location, 5.f, 1, speed)
{
	angle = Angle;
}

void SpiralBullets::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y * cos(angle);
	newLocation.x += speed.x * sin(angle) * -1;
	SetLocation(newLocation);
}

void SpiralBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 170, 220));
}

bool SpiralBullets::isScreenOut()
{
	bool ret = ((GetLocation().y + GetRadius()) <= 0 || (GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (HEIGHT <= (GetLocation().y - GetRadius())) || (WHITH <= (GetLocation().x - GetRadius()));
	return ret;
}