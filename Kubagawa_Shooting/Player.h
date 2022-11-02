#pragma once
#include "CharaBase.h"
#include "StraightBullets.h"

class Player :
    public CharaBase
{
private:
    int score;
    int life;
public:
    Player(T_Location location);
public:
    void Update() override;
    void Draw() override;
    void Hit(int damage) override;
    bool LifeCheck();
    int GetScore();

};

