#pragma once
#include "SphereCollider.h"
#include"BulletsBase.h"
#define BULLET 990
class CharaBase : public SphereCollider
{
protected:
	BulletsBase** bullets;
	T_Location speed;    //’e‚Ì‘¬“x
	int* image;    //’e‚Ì‰æ‘œ
	int waitShotTimer;    //”­ËŠ´Šo

public:
	CharaBase(T_Location location, float radius, T_Location speed);
public:
	virtual void Update()= 0;   //ƒˆ‰¼‘zŠÖ”
	virtual void Draw() = 0;    //•`‰æ
	virtual void Hit(int damage) = 0;    //“–‚½‚è”»’è
	BulletsBase** GetBullets();    //’e
	void DeleteBullet(int bulletNum);    //’e‚ğíœ
};