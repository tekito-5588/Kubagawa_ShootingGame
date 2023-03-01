#include "Recovery.h"
#include "DxLib.h"

Recovery::Recovery(T_Location location)
	:ItemBase(location, 5.f, E_ITEM_TYPE::Heal, T_Location{0,1}), volume(2)
{

}

void Recovery::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);
}

void Recovery::Draw()
{
	int ImageItem = LoadGraph("images/Item.png");

	DrawGraph(GetLocation().x - 10, GetLocation().y - 35, ImageItem, FALSE);
	//DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 255));
}

int Recovery::GetVolume()
{
	return volume;
}