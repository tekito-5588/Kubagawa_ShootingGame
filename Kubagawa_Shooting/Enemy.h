#pragma once
#include "CharaBase.h"
#include"StraightBullets.h"
#include"SpiralBullets.h"

class Enemy :
    public CharaBase
{
private:
    int hp;    //ヒットポイント
    int point;    //得点
    int shotNum;    //弾の数

    float angle;
public:
    Enemy(T_Location location);

public:
    virtual void Update() override;    //更新
    virtual void Draw() override;    //描画
    virtual void Hit(int damage) override;    //当たり判定
    bool HpCheck();    //体力チェック
    int GetPoint();    //得点の計算
    void Move();
};

