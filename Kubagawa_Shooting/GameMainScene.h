#pragma once
#include "AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"ItemBase.h"
#include"Recovery.h"
#define WINDOW_HEIGHT 720
#define WINDOW_WHITH 1280

class GameMainScene :public AbstractScene
{
public:
	Player* player;
	Enemy** enemy;
	ItemBase** items;
public:
	GameMainScene();
	//デストラクタ
	virtual ~GameMainScene() {};

	//描画以外の更新を実装する
	virtual void Update() override;

	//描画に関することを実装する
	virtual void Draw() const override;

	//シーンの変更処理
	virtual AbstractScene* ChangeScene() override;

	void DeleteEnemy(int enemyNum);
};

