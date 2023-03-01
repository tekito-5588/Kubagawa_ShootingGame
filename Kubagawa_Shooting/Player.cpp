#include"DxLib.h"
#include "Player.h"
#include "BulletsBase.h"
#include"KeyManager.h"
#include "recovery.h"

Player::Player(T_Location location) :CharaBase(location, 10.f, T_Location{ 2,2 })
        , score(0),life(10)
{
	bullets = new BulletsBase * [BULLET];
	for (int i = 0; i < BULLET; i++)
	{
		bullets[i] = nullptr;
	}
	waitShotTimer = 0;
	//player = ("Images/Player.png");
}

void Player::Update()
{
	T_Location newLocation = GetLocation();
	if (KeyManager::OnKeyPreased(KEY_INPUT_W))
	{newLocation.y -= speed.y;
    }
	if (KeyManager::OnKeyPreased(KEY_INPUT_A))
	{
		newLocation.x -= speed.x;
	}
	if (KeyManager::OnKeyPreased(KEY_INPUT_S))
	{
		newLocation.y += speed.y;
	}
	if (KeyManager::OnKeyPreased(KEY_INPUT_D))
	{
		newLocation.x += speed.x;
	}

	SetLocation(newLocation);

	int bulletCount;
	for (bulletCount = 0; bulletCount < BULLET; bulletCount++)
	{
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

	//���N���b�N����������A�v���C���[�̒e�����˂����
	if (KeyManager::OnMousePreased(MOUSE_INPUT_LEFT))
	{
		//1/6�̕b���Œe��1�����˂����B
		if(waitShotTimer == 10)
		{
			waitShotTimer = 0;
			if (bulletCount < BULLET && bullets[bulletCount] == nullptr)
			{
				//�e�͂܂������ɔ�сA��ʂ̏�ɍs��
				bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0,-2 });
			}
		}
		waitShotTimer++;
	}
}
void Player::Draw()
{
#define _DEBUG_MODE_
	
#ifdef _DEBUG_MODE_
	//HP�\��
	DrawFormatString(10, 10, GetColor(255, 255, 255), "life = %d", life);
	//�X�R�A�\��
	DrawFormatString(30, 30, GetColor(255, 255, 255), "score = %d", score);
#endif
	ImagePlayer = LoadGraph("images/Player.png");

	DrawGraph(GetLocation().x - 15, GetLocation().y - 15, ImagePlayer, TRUE);
	//DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));

	for (int bulletCount = 0; bulletCount < BULLET; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}
void Player::Hit(int damage)
{
	if (0 <= damage)
	{
		life -= damage;
		if (life <= 0)
		{
			life = 0;
		}
	}
}
void Player::Hit(ItemBase* item)
{
	//�A�C�e��
	switch (item->GetType())
	{
	case E_ITEM_TYPE::Heal:
	{
		//�񕜃A�C�e���ɓ���������AHP��2�񕜂���B
		Recovery* recovery = dynamic_cast<Recovery*>(item);
		life += recovery->GetVolume();
		break;
	}
	default:
		break;
	}
}

bool Player::LifeCheck()
{
	bool ret = (life <= 0);
	return ret;
}

int Player::GetScore() 
{
	//�X�R�A
	return score;
}

void Player::AddScore(int score)
{
	//�X�R�A�𑝂₷
	if (0 <= score) {
		this->score += score;
	}
}