#pragma once
#include "AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"ItemBase.h"
#include"Recovery.h"
#include"GameClear.h"
#include"GameOver.h"
#define HEIGHT 720
#define WIDTH 1280

class GameMainScene :public AbstractScene
{
private:
	int enemyCount;

public:
	Player* player;
	Enemy** enemy;
	ItemBase** items;
	
public:
	GameMainScene();
	//�f�X�g���N�^
	virtual ~GameMainScene() {};

	//�`��ȊO�̍X�V����������
	virtual void Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;

	//�G�l�~�[�̍폜
	void DeleteEnemy(int enemyNum);
};

