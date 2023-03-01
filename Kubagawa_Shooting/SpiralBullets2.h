#pragma once
#include "BulletsBase.h"
class SpiralBullets2 :
    public BulletsBase
{
private:
	int angle;
public:
	SpiralBullets2(T_Location location, float Speed, int Angle);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;
};

