#pragma once
#include "CharaBase.h"
#include"StraightBullets.h"
#include"SpiralBullets.h"
#include"SpiralBullets2.h"

struct MoveInfomation
{
    int pettern; // �s���p�^�[��
    T_Location targetLocation;//�ړI�n
    int next;//���̔z��ԍ�
    int witeTimeFlame;//�҂�����
    int attackType;//�U�����
};

class Enemy :
    public CharaBase
{
private:
    int hp;    //�q�b�g�|�C���g
    int point;    //���_
    int shotNum;    //�e�̐�

    float angle;

    int current = 0;
    int waitTime = 0;
    MoveInfomation moveInfo[5];

public:
    Enemy(T_Location location);

public:
    virtual void Update() override;    //�X�V
    virtual void Draw() override;    //�`��
    virtual void Hit(int damage) override;    //�����蔻��
    bool HpCheck();    //�̗̓`�F�b�N
    int GetPoint();    //���_�̌v�Z
    void Move();
    void inputCSV();

};
