#include"DxLib.h"
#include "SpiralBullets.h"
#include"GameMainScene.h"
#include"BulletsBase.h"
#define _USE_MATH_DEFINES
#include<math.h>

//ƒvƒŒƒCƒ„[‚ğ²‚É‰ñ“]‚·‚é’e

SpiralBullets::SpiralBullets(T_Location location, float Speed,int Angle)
	:BulletsBase(location, 5.f, 1, T_Location{ 0,0 })
{
	int deg = Angle % 360;
	double rad = (M_PI / 180) * deg;
	float x = (abs(deg) == 90 || abs(deg) == 270) ? 0 : cos(rad);
	float y = sin(rad);

	this->speed = T_Location{ (Speed * x),(Speed * y) };
}

//’e‚Ì“®‚«‚ğŒvZ‚·‚é
void SpiralBullets::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	newLocation.x += speed.x;
	SetLocation(newLocation);
}
//’e‚Ì•`‰æ
void SpiralBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 170, 220));
}

//‰æ–ÊŠO‚Éo‚½‚ç’e‚ğÁ‹‚·‚é
bool SpiralBullets::isScreenOut()
{
	bool ret = ((GetLocation().y + GetRadius()) <= 0 || (GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (HEIGHT <= (GetLocation().y - GetRadius())) || (WIDTH <= (GetLocation().x - GetRadius()));
	return ret;
}