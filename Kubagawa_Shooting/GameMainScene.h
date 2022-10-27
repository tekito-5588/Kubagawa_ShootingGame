#pragma once
#include "AbstractScene.h"
#include"Player.h"
#include"Enemy.h"

class GameMainScene :public AbstractScene
{
public:
	Player* player;
	Enemy** enemy;
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
};

