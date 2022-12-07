#pragma once
#include "BulletsBase.h"
class SpiralBullets :public BulletsBase
{
private:
	int angle;
public:
	SpiralBullets(T_Location location, float Speed, int Angle);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;
};