#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,100 };
	player = new Player(location);
	
	enemy = new Enemy*[10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
	enemy[0] = new Enemy(T_Location{ 200,0 });
}
//描画以外の更新を実装する
void GameMainScene::Update()
{
	player->Update();
	
	int enemyCount;
	
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Update();
	}

	BulletsBase** bullet = player->GetBullets();
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		for (int bulletCount = 0; bulletCount < 30; bulletCount++)
		{
			if (bullet[bulletCount] == nullptr)
			{
				break;
			}
			if (enemy[enemyCount]->HitSphere(bullet[bulletCount]))
			{
				//エネミーにプレイヤーがヒットしている
				//エネミーにダメージを与えます
				enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());

				//弾を削除します
				player->DeleteBullet(bulletCount);
				bulletCount--;

				//エネミーのHPが0だったら、エネミーを削除します
				if (enemy[enemyCount]->HpCheck())
				{
					//スコアの加算
					player->AddScore(enemy[enemyCount]->GetPoint());

					//エネミーの削除
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;

					for (int i = enemyCount; i < 10; i++)
					{
						if (enemy[i] == nullptr)
						{
							break;
						}
						enemy[i - 1] = enemy[i];
						enemy[i] = nullptr;
					}
					enemyCount--;
					break;
				}
			}
		}
	}
}

//描画に関することを実装する
void GameMainScene::Draw() const
{
	player->Draw();

	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Draw();
	}
}

//シーンの変更処理
AbstractScene* GameMainScene::ChangeScene()
{
	return this;
}

void GameMainScene::DeleteEnemy(int enemyNum)
{
	delete enemy[enemyNum];
	enemy[enemyNum] = nullptr;

	for (int i = enemyNum; i < (10 - 1); i++)
	{
		if (enemy[i + 1] == nullptr)
		{
			break;
		}
		enemy[i] = enemy[i + 1];
		enemy[i + 1] = nullptr;
	}
	enemyNum--;
}