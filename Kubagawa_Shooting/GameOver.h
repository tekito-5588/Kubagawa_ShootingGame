#pragma once
#include "AbstractScene.h"
class GameOver :
    public AbstractScene
{
private:

public:
	//�R���X�g���N�^
	GameOver();

	//�f�X�g���N�^
	virtual ~GameOver();

	//�`��ȊO�̍X�V������
	void Update() override;

	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;

};

