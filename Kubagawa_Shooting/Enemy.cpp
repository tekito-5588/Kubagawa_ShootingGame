#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include<math.h>
#define _ENEMY_BULLET_ALL_ 100

struct MoveInfomation
{
	int pettern; // 行動パターン
	T_Location targetLocation;//目的地
	int next;//次の配列番号
	int witeTimeFlame;//待ち時間
	int attackType;//攻撃種類
};

MoveInfomation moveInfo[5] =
{
	{0,640,150,1,0,0},
	{0,1200.4,150,2,0,2},
	{1,0,0,3,300,1},
	{0,80.2,150,4,0,2},
	{1,0,0,1,300,1},
};

T_Location locations[3] =
{
	{640,150},
	{1200.4,150},
	{80.2,150},
};

int next[3] =
{
	1,
	2,
	1
};

int current = 0;
int waitTime = 0;

Enemy::Enemy(T_Location location):
	CharaBase(location, 20.f, T_Location{ 2,2 })
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
	switch (moveInfo[current].pettern)
	{
	case 0:
		Move();
		break;
	case 1:
		waitTime++;
		if (moveInfo[current].witeTimeFlame <= waitTime)
		{
			waitTime = 0;
			current = moveInfo[current].next;
		}
	default:
		break;
	}

	/*T_Location newLocation = GetLocation();
	if (GetLocation().y != locations[1].y)
	{
		if (GetLocation().y < locations[1].y)
		{
			newLocation.y += speed.y;
			SetLocation(newLocation);
		}
	}
	else if (GetLocation().y != locations[1].y)
	{
		if (GetLocation().y > locations[1].y)
		{
			newLocation.y -= speed.y;
			SetLocation(newLocation);
		}
	}
	else if (GetLocation().x != locations[1].y)
	{
		if (GetLocation().y < locations[1].y)
		{
			newLocation.y += speed.y;
			SetLocation(newLocation);
		}
	}
	if (GetLocation().x != locations[1].x)
	{
		if (GetLocation().x > locations[1].x)
		{
			newLocation.x -= speed.x;
			SetLocation(newLocation);
		}
	}*/
	
	//エネミーの弾
	int bulletCount;
	for (bulletCount = 0; bulletCount < BULLET; bulletCount++)
	{
		//常時弾を発射する
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Update();

		//画面外に行ったら弾を消す
		if (bullets[bulletCount]->isScreenOut())
		{
			DeleteBullet(bulletCount);
			bulletCount--;
		}
	}

	/*if (waitShotTimer == 3)
	{
		waitShotTimer = 0;*/
		if (moveInfo[current].attackType != 0) 
		{
			if (bulletCount < 30 && bullets[bulletCount] == nullptr)
			{
				if (moveInfo[current].attackType == 1)
				{
					//弾を作る処理
					bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2});

					/*shotNum += 5;*/
				}
				else if (moveInfo[current].attackType == 2)
				{
					//弾を作る処理
					shotNum++;
					bullets[bulletCount] = new SpiralBullets(GetLocation(), 2.f, (20 * shotNum));
					/*shotNum += 5;*/
				}
			}
		}
	//}
	//waitShotTimer++;
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

void Enemy::Move()
{
	//今いる座標を保存して次の座標に取得する。
	T_Location newLocation = GetLocation();

	//同じ座標にいたら
	if ((newLocation.x == moveInfo[current].targetLocation.x) &&
		(newLocation.y == moveInfo[current].targetLocation.y))
	{
		//次の座標に移動させる。
		current = moveInfo[current].next;
	}
	//目的地にいなかったとき
	else
	{
		//Xがたどり着かなかったとき
		if (newLocation.x != moveInfo[current].targetLocation.x)
		{
			//Y座標が大きかった時値を増やす
			if (newLocation.x < moveInfo[current].targetLocation.x)
			{
				newLocation.x += speed.x;
				//今の座標<目的地
				//目的地<次の座標
				if ((GetLocation().x <= locations[current].x) &&
					(moveInfo[current].targetLocation.x) <= newLocation.x)
				{
					//目的地を超えたときに目的地に直す
					newLocation.x = moveInfo[current].targetLocation.x;
				}
			}
			else
			{
				newLocation.x -= speed.x;
                //次の座標　< 目的地
				//目的地　< 今の座標
				if ((newLocation.x <= moveInfo[current].targetLocation.x) &&
					(moveInfo[current].targetLocation.x <= GetLocation().x))
				{
					//強制的に目的地に直す
					newLocation.x = moveInfo[current].targetLocation.x;
				}
			}
		}
		//Yがたどり着かなかったとき
		if (newLocation.y != moveInfo[current].targetLocation.y)
		{
			//Y座標が大きかった時値を増やす
			if (newLocation.y < moveInfo[current].targetLocation.y)
			{
				newLocation.y += speed.y;
				//今の座標<目的地
				//目的地<次の座標
				if ((GetLocation().y <= locations[current].y) &&
					(moveInfo[current].targetLocation.y) <= newLocation.y)
				{
					//目的地を超えたときに目的地に直す
					newLocation.y = moveInfo[current].targetLocation.y;
				}
			}
			else
			{
				newLocation.y -= speed.y;
				//次の座標　< 目的地
				//目的地　< 今の座標
				if ((newLocation.y <= moveInfo[current].targetLocation.y) &&
					(moveInfo[current].targetLocation.y <= GetLocation().y))
				{
					//強制的に目的地に直す
					newLocation.y = moveInfo[current].targetLocation.y;
				}
			}
		}
	}
	SetLocation(newLocation);
}