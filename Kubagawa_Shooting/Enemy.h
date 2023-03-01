#pragma once
#include "CharaBase.h"
#include"StraightBullets.h"
#include"SpiralBullets.h"
#include"SpiralBullets2.h"

struct MoveInfomation
{
    int pettern; // 行動パターン
    T_Location targetLocation;//目的地
    int next;//次の配列番号
    int witeTimeFlame;//待ち時間
    int attackType;//攻撃種類
};

class Enemy :
    public CharaBase
{
private:
    int hp;    //ヒットポイント
    int point;    //得点
    int shotNum;    //弾の数

    float angle;

    int current = 0;
    int waitTime = 0;
    MoveInfomation moveInfo[5];

public:
    Enemy(T_Location location);

public:
    virtual void Update() override;    //更新
    virtual void Draw() override;    //描画
    virtual void Hit(int damage) override;    //当たり判定
    bool HpCheck();    //体力チェック
    int GetPoint();    //得点の計算
    void Move();
    void inputCSV();

};
