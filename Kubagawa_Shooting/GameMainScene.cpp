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

	items=new ItemBase*[10];
	for (int i = 0; i < 10; i++)
	{
		items[i] = nullptr;
	}
}
//描画以外の更新を実装する
void GameMainScene::Update()
{
	player->Update();

	int enemyCount;

	int playerCount;
	
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Update();
	}

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Update();
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
					for (int i = 0; i < 10; i++)
					{
						if (items[i] == nullptr)
						{
							items[i] = new Recovery(enemy[enemyCount]->GetLocation());
							break;
						}
					}
					

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

	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		bullet = enemy[enemyCount]->GetBullets();

		for (int i = 0; i < 30; i++)
		{
			if (bullet[i] == nullptr)
			{
				break;
			}

			if (player->HitSphere(bullet[i]))
			{
				player->Hit(bullet[i]->GetDamage());

				enemy[enemyCount]->DeleteBullet(i);
				i--;
			}
		}
	}

	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (items[itemCount] == nullptr)
		{
			break;
		}
		//アイテム消滅処理
		if (items[itemCount]->HitSphere(player) == true)
		{
			//回復処理
			player->Hit(items[itemCount]);

			delete items[itemCount];
			items[itemCount] = nullptr;

			//配列を前に詰める
			for (int i = itemCount + 1; i < 10; i++)
			{
				if (items[i] == nullptr)
				{
					break;
				}
				items[i - 1] = items[i];
				items[i] = nullptr;
			}
			itemCount--;
			
		}
	}

	//敵の弾を取ってくる
	//for(弾をループで参照){
	//if(敵の弾と　プレイヤーの当たり判定){
	//プレイヤーにダメージを与える
	//}
	//}

	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		BulletsBase** bullet = enemy[enemyCount]->GetBullets();
		for (int bulletCount = 0; bulletCount < 30; bulletCount++)
		{
			if (bullet[bulletCount] == nullptr)
			{
				break;
			}
			if (player->HitSphere(bullet[bulletCount]))
			{
				//エネミーにプレイヤーがヒットしている
				//エネミーにダメージを与えます
				player->Hit(bullet[bulletCount]->GetDamage());

				//弾を削除します
				enemy[enemyCount]->DeleteBullet(bulletCount);
				bulletCount--;

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
	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Draw();
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