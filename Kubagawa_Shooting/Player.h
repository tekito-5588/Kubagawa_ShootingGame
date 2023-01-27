#pragma once
#include "CharaBase.h"
#include "StraightBullets.h"

class Player :
    public CharaBase
{
private:
    int score;  //���_
    int life;  //�c�@
public:
    Player(T_Location location);
public:
    void Update() override;  //�X�V
    void Draw() override;  //�`��
    void Hit(int damage) override;
    void Hit(class ItemBase* item);
    bool LifeCheck();
    int GetScore();
    void AddScore(int score);
};

