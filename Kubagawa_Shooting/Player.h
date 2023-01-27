#pragma once
#include "CharaBase.h"
#include "StraightBullets.h"

class Player :
    public CharaBase
{
private:
    int score;  //得点
    int life;  //残機
public:
    Player(T_Location location);
public:
    void Update() override;  //更新
    void Draw() override;  //描画
    void Hit(int damage) override;
    void Hit(class ItemBase* item);
    bool LifeCheck();
    int GetScore();
    void AddScore(int score);
};

