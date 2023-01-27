#pragma once
#include "SphereCollider.h"
class BulletsBase : public SphereCollider
{
private:
	int damage;    //�e�̃_���[�W
	
protected:
	T_Location speed;    //�e�̑��x

public:
	//�e�̊�b
	BulletsBase(T_Location location, float radius, int damage, T_Location speed);

public:
	virtual void Update() = 0;    //�X�V
	virtual void Draw() = 0;    //�`��
	virtual bool isScreenOut() = 0;    //��ʐݒ�
	int GetDamage();    //�_���[�W�ݒ�
};

