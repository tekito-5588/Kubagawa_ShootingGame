#pragma once
#include "SphereCollider.h"
class BulletsBase : public SphereCollider
{
private:
	int damage;    //弾のダメージ
	
protected:
	T_Location speed;    //弾の速度

public:
	//弾の基礎
	BulletsBase(T_Location location, float radius, int damage, T_Location speed);

public:
	virtual void Update() = 0;    //更新
	virtual void Draw() = 0;    //描画
	virtual bool isScreenOut() = 0;    //画面設定
	int GetDamage();    //ダメージ設定
};

