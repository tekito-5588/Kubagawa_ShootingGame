#pragma once

class KeyManager
{
private:
	static char oldKey[256];
	static char NowKey[256];

	static int oldMouse;
	static int NowMouse;

private:
	KeyManager() = default;

public:
	static void Update();       //キーの更新
	static bool OnKeyClicked(int Key);   //押した瞬間
	static bool OnKeyReleased(int Key);  //離した瞬間
	static bool OnKeyPreased(int Key);   //押している間

	static bool OnMouseClicked(int Key);
	static bool OnMouseyReleased(int Key);
	static bool OnMousePreased(int Key);
};