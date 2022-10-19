#pragma once
#include "BulletsBase.h"
class StraightBullets :public BulletsBase
{
public:
	StraightBullets(T_Location location);

public:
	void Update() override;
	void Draw() override;
};

