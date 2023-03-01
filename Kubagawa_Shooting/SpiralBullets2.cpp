#include"DxLib.h"
#include "SpiralBullets2.h"
#include"GameMainScene.h"
#include"BulletsBase.h"
#define _USE_MATH_DEFINES
#include<math.h>

//ƒvƒŒƒCƒ„[‚ğ²‚É‰ñ“]‚·‚é’e

SpiralBullets2::SpiralBullets2(T_Location location, float Speed, int Angle)
	:BulletsBase(location, 5.f, 1, T_Location{ 0,0 })
{
	int deg = Angle % 360;
	double rad = (M_PI / 180) * deg;
	float x = (abs(deg) == 90 || abs(deg) == 270) ? 0 : cos(rad);
	float y = sin(rad);

	this->speed = T_Location{ (Speed * x),(Speed * y) };
}

//’e‚Ì“®‚«‚ğŒvZ‚·‚é
void SpiralBullets2::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	newLocation.x += speed.x;
	SetLocation(newLocation);
}
//’e‚Ì•`‰æ
void SpiralBullets2::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 170, 220));
}

//‰æ–ÊŠO‚Éo‚½‚ç’e‚ğÁ‹‚·‚é
bool SpiralBullets2::isScreenOut()
{
	bool ret = ((GetLocation().y + GetRadius()) <= 0 || (GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (HEIGHT <= (GetLocation().y - GetRadius())) || (WIDTH <= (GetLocation().x - GetRadius()));
	return ret;
}