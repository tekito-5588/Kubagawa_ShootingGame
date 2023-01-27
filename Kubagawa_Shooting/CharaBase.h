#pragma once
#include "SphereCollider.h"
#include"BulletsBase.h"
#define BULLET 990
class CharaBase : public SphereCollider
{
protected:
	BulletsBase** bullets;
	T_Location speed;    //�e�̑��x
	int* image;    //�e�̉摜
	int waitShotTimer;    //���ˊ��o

public:
	CharaBase(T_Location location, float radius, T_Location speed);
public:
	virtual void Update()= 0;   //�������z�֐�
	virtual void Draw() = 0;    //�`��
	virtual void Hit(int damage) = 0;    //�����蔻��
	BulletsBase** GetBullets();    //�e
	void DeleteBullet(int bulletNum);    //�e���폜
};