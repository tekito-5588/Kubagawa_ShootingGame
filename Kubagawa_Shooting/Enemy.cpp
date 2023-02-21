#include"DxLib.h"
#include "Enemy.h"
#include"BulletsBase.h"
#include"GameClear.h"
#include<math.h>
#define _ENEMY_BULLET_ALL_ 100

void Enemy::inputCSV()
{
	FILE* fp;  //FILE�^�\����
	errno_t error;  //fopen_s�̃G���[�m�F

	error = fopen_s(&fp, "CSV/Zahyou.csv","r");
	if (error != 0)
	{
		//�G���[����
		return;
	}
	else
	{
		//�t�@�C�����J����
		char line[100];
		for (int i = 0; fgets(line, 100, fp) != NULL; i++)
		/*while (fgets(line, 100, fp) != NULL)*/
		{
			sscanf_s(line, "%d,%f,%f,%d,%d,%d",
				&moveInfo[i].pettern,
				&moveInfo[i].targetLocation.x,
				&moveInfo[i].targetLocation.y,
				&moveInfo[i].next,
				&moveInfo[i].witeTimeFlame,
				&moveInfo[i].attackType
			);
		}
		return;
	}

	fclose(fp);  //�t�@�C�������
}

Enemy::Enemy(T_Location location):
	CharaBase(location, 20.f, T_Location{ 1,1 })
    ,hp(10),point(10),shotNum(0)
{
	bullets = new BulletsBase * [BULLET];
	for (int i = 0; i < BULLET; i++)
	{
		bullets[i] = nullptr;
	}
	waitShotTimer = 0;
	angle = 0;

	inputCSV();
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
	
	//�G�l�~�[�̒e
	int bulletCount;
	for (bulletCount = 0; bulletCount < BULLET; bulletCount++)
	{
		//�펞�e�𔭎˂���
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Update();

		//��ʊO�ɍs������e������
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
			if (bulletCount < 990 && bullets[bulletCount] == nullptr)
			{
				
					if (moveInfo[current].attackType == 1)
					{
						//�e����鏈��
						bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });

						/*shotNum += 5;*/
					}
					else if (moveInfo[current].attackType == 2)
					{
						//�e����鏈��
						shotNum++;
						bullets[bulletCount] = new SpiralBullets(GetLocation(), 3.f, (20 * shotNum));
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
	//��������W��ۑ����Ď��̍��W�Ɏ擾����B
	T_Location newLocation = GetLocation();

	//�������W�ɂ�����
	if ((newLocation.x == moveInfo[current].targetLocation.x) &&
		(newLocation.y == moveInfo[current].targetLocation.y))
	{
		//���̍��W�Ɉړ�������B
		current = moveInfo[current].next;
	}
	//�ړI�n�ɂ��Ȃ������Ƃ�
	else
	{
		//X�����ǂ蒅���Ȃ������Ƃ�
		if (newLocation.x != moveInfo[current].targetLocation.x)
		{
			//Y���W���傫���������l�𑝂₷
			if (newLocation.x < moveInfo[current].targetLocation.x)
			{
				newLocation.x += speed.x;
				//���̍��W<�ړI�n
				//�ړI�n<���̍��W
				if ((GetLocation().x <= moveInfo[current].targetLocation.x) &&
					(moveInfo[current].targetLocation.x) <= newLocation.x)
				{
					//�ړI�n�𒴂����Ƃ��ɖړI�n�ɒ���
					newLocation.x = moveInfo[current].targetLocation.x;
				}
			}
			else
			{
				newLocation.x -= speed.x;
                //���̍��W�@< �ړI�n
				//�ړI�n�@< ���̍��W
				if ((newLocation.x <= moveInfo[current].targetLocation.x) &&
					(moveInfo[current].targetLocation.x <= GetLocation().x))
				{
					//�����I�ɖړI�n�ɒ���
					newLocation.x = moveInfo[current].targetLocation.x;
				}
			}
		}
		//Y�����ǂ蒅���Ȃ������Ƃ�
		if (newLocation.y != moveInfo[current].targetLocation.y)
		{
			//Y���W���傫���������l�𑝂₷
			if (newLocation.y < moveInfo[current].targetLocation.y)
			{
				newLocation.y += speed.y;
				//���̍��W<�ړI�n
				//�ړI�n<���̍��W
				if ((GetLocation().y <= moveInfo[current].targetLocation.y) &&
					(moveInfo[current].targetLocation.y) <= newLocation.y)
				{
					//�ړI�n�𒴂����Ƃ��ɖړI�n�ɒ���
					newLocation.y = moveInfo[current].targetLocation.y;
				}
			}
			else
			{
				newLocation.y -= speed.y;
				//���̍��W�@< �ړI�n
				//�ړI�n�@< ���̍��W
				if ((newLocation.y <= moveInfo[current].targetLocation.y) &&
					(moveInfo[current].targetLocation.y <= GetLocation().y))
				{
					//�����I�ɖړI�n�ɒ���
					newLocation.y = moveInfo[current].targetLocation.y;
				}
			}
		}
	}
	SetLocation(newLocation);
}