#pragma once
#include"AbstractScene.h"

class Title :public AbstractScene
{
private:
	
public:
	//�R���X�g���N�^
	Title();

	//�f�X�g���N�^
	virtual ~Title();

	//�`��ȊO�̍X�V������
	void Update() override;

	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};