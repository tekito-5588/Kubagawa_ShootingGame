#pragma once
#include "BulletsBase.h"
class SpiralBullets :public BulletsBase
{
public:
	SpiralBullets(T_Location location, T_Location speed);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;
};

