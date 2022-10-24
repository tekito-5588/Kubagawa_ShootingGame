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
	static void Update();       //�L�[�̍X�V
	static bool OnKeyClicked(int Key);   //�������u��
	static bool OnKeyReleased(int Key);  //�������u��
	static bool OnKeyPreased(int Key);   //�����Ă����

	static bool OnMouseClicked(int Key);
	static bool OnMouseyReleased(int Key);
	static bool OnMousePreased(int Key);
};