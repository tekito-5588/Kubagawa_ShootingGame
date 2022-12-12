#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include<math.h>
#define _ENEMY_BULLET_ALL_ 100
T_Location locations[4] =
{
	{200,0},
	{400,300},
	{800,240},
	{500,0}
};

Enemy::Enemy(T_Location location):
	CharaBase(location, 20.f, T_Location{ 0,0 })
    ,hp(10),point(10),shotNum(0)
{
	bullets = new BulletsBase * [BULLET];
	for (int i = 0; i < BULLET; i++)
	{
		bullets[i] = nullptr;
	}
	waitShotTimer = 0;
	angle = 0;
}

void Enemy::Update()
{
	T_Location newLocation = /*GetLocation()*/locations[0];
	newLocation.y += speed.y;
	newLocation.x += speed.x;
	SetLocation(newLocation);

	int bulletCount;
	for (bulletCount = 0; bulletCount < BULLET; bulletCount++)
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

	if (waitShotTimer == 3)
	{
		waitShotTimer = 0;
		if (bulletCount < BULLET && bullets[bulletCount] == nullptr)
		{
			bullets[bulletCount] = new SpiralBullets(GetLocation(), 2.f, (15 * shotNum));
			shotNum+=5;
		}
	}
	waitShotTimer++;
}
void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

	for (int bulletCount = 0; bulletCount < BULLET; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}

	DrawFormatString(0, 400, 0xffffff, "%d", shotNum);
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