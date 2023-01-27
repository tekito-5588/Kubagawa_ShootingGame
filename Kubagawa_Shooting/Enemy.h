#pragma once
#include "CharaBase.h"
#include"StraightBullets.h"
#include"SpiralBullets.h"

class Enemy :
    public CharaBase
{
private:
    int hp;    //�q�b�g�|�C���g
    int point;    //���_
    int shotNum;    //�e�̐�

    float angle;
public:
    Enemy(T_Location location);

public:
    virtual void Update() override;    //�X�V
    virtual void Draw() override;    //�`��
    virtual void Hit(int damage) override;    //�����蔻��
    bool HpCheck();    //�̗̓`�F�b�N
    int GetPoint();    //���_�̌v�Z
    void Move();
};

