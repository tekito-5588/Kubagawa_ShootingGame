#pragma once
#include "AbstractScene.h"
class GameMainScene :public AbstractScene
{
public:
	//�f�X�g���N�^
	virtual ~GameMainScene() {};

	//�`��ȊO�̍X�V����������
	virtual void Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;
};

