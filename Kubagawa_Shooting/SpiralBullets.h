#pragma once
#include "BulletsBase.h"
class SpiralBullets :public BulletsBase
{
private:
	float angle;
public:
	SpiralBullets(T_Location location, T_Location speed, float Angle);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;
};