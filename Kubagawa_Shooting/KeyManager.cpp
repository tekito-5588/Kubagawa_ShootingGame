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
	//ボタンを離した瞬間
	bool ret = ((~NowKey[Key] != 1) && (oldKey[Key] == 1)); //反転でも処理できる
	return ret;
}

bool KeyManager::OnKeyPreased(int Key)
{
	//ボタンを押している間
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
	//ボタンを離した瞬間
	bool ret = ((~NowMouse & Key) && (oldMouse & Key)); //反転でも処理できる
	return ret;
}

bool KeyManager::OnMousePreased(int Key)
{
	//ボタンを押している間
	bool ret = ((NowMouse & Key));
	return ret;
}