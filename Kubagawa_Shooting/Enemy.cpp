#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include<math.h>

Enemy::Enemy(T_Location location):
	CharaBase(location, 20.f, T_Location{ 0,0.5 })
    ,hp(10),point(10)
{
	bullets = new BulletsBase * [40];
	for (int i = 0; i < 40; i++)
	{
		bullets[i] = nullptr;
	}
	waitShotTimer = 0;
	angle = 0;
}

void Enemy::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);
	/*SetLocation(newLocation);*/

	int bulletCount;
	for (bulletCount = 0; bulletCount < 40; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Update();

		//‰æ–ÊŠO‚És‚Á‚½‚ç’e‚ðÁ‚·
		if (bullets[bulletCount]->isScreenOut())
		{
			DeleteBullet(bulletCount);
			bulletCount--;
		}
	}

	if (waitShotTimer == 10)
	{
		waitShotTimer = 0;
		if (bulletCount < 40 && bullets[bulletCount] == nullptr)
		{
			bullets[bulletCount] = new SpiralBullets(GetLocation(), T_Location{ 2,2 }, angle);
			angle += 3;
		}
	}
	waitShotTimer++;
}
void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

	for (int bulletCount = 0; bulletCount < 40; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}
void Enemy::Hit(int damage)
{
	if (0 < damage)
	{
		hp -= damage;
		if (hp < 0)
		{
			hp = 0;
		}
	}
}
bool Enemy::HpCheck()
{
	bool ret = (hp <= 0);
	return ret;
}
int Enemy::GetPoint()
{
	return point;
}