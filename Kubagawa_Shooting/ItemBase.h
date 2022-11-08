#pragma once
#include "SphereCollider.h"
#include "E_ITEM_TYPE.h"

class ItemBase :
    public SphereCollider
{
private:
    E_ITEM_TYPE type;

protected:
    T_Location speed;

public:
    virtual void Update();
    virtual void Draw();
    E_ITEM_TYPE GetType();
};

