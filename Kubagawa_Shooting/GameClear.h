#pragma once
#include"AbstractScene.h"

class GameClear :public AbstractScene
{
private:

public:
	//�R���X�g���N�^
	GameClear();

	//�f�X�g���N�^
	virtual ~GameClear();

	//�`��ȊO�̍X�V������
	void Update() override;

	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};