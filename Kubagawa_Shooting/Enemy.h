#pragma once
#include "CharaBase.h"
#include"StraightBullets.h"
#include"SpiralBullets.h"

class Enemy :
    public CharaBase
{
private:
    int hp;
    int point;
    int shotNum;

    float angle;
public:
    Enemy(T_Location location);

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual void Hit(int damage) override;
    bool HpCheck();
    int GetPoint();
};

