#include"DxLib.h"
#include "KeyManager.h"

char KeyManager::oldKey[256];
char KeyManager::NowKey[256];

int KeyManager::oldMouse;
int KeyManager::NowMouse;

void KeyManager::Update()
{
	for (int i = 0; i < 255; i++)
	{
		oldKey[i] = NowKey[i];
	}

	if (GetHitKeyStateAll(NowKey) == -1)
	{
		throw - 1;
	}

	oldMouse = NowMouse;
	NowMouse = GetMouseInput();
}

bool KeyManager::OnKeyClicked(int Key)
{
	bool cet = ((NowKey[Key] == 1) && (~oldKey[Key] != 1));
	return cet;
}

bool KeyManager::OnKeyReleased(int Key)
{
	//ƒ{ƒ^ƒ“‚ð—£‚µ‚½uŠÔ
	bool ret = ((~NowKey[Key] != 1) && (oldKey[Key] == 1)); //”½“]‚Å‚àˆ—‚Å‚«‚é
	return ret;
}

bool KeyManager::OnKeyPreased(int Key)
{
	//ƒ{ƒ^ƒ“‚ð‰Ÿ‚µ‚Ä‚¢‚éŠÔ
	bool pet = ((NowKey[Key] == 1));
	return pet;
}


bool KeyManager::OnMouseClicked(int Key)
{
	bool ret = ((NowMouse & Key) && (~oldMouse & Key));
	return ret;
}

bool KeyManager::OnMouseyReleased(int Key)
{
	//ƒ{ƒ^ƒ“‚ð—£‚µ‚½uŠÔ
	bool ret = ((~NowMouse & Key) && (oldMouse & Key)); //”½“]‚Å‚àˆ—‚Å‚«‚é
	return ret;
}

bool KeyManager::OnMousePreased(int Key)
{
	//ƒ{ƒ^ƒ“‚ð‰Ÿ‚µ‚Ä‚¢‚éŠÔ
	bool pet = ((NowMouse & Key));
	return pet;
}