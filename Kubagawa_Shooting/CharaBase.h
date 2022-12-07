#pragma once
#include "SphereCollider.h"
#include"BulletsBase.h"
#define BULLET 990
class CharaBase : public SphereCollider
{
protected:
	BulletsBase** bullets;
	T_Location speed;
	int* image;
	int waitShotTimer;

public:
	CharaBase(T_Location location, float radius, T_Location speed);
public:
	virtual void Update()= 0;   //èÉêàâºëzä÷êî
	virtual void Draw() = 0;
	virtual void Hit(int damage) = 0;
	BulletsBase** GetBullets();
	void DeleteBullet(int bulletNum);
};