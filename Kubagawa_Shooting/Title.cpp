#include"DxLib.h"
#include"Title.h"
#include"GameMainScene.h"
#include"KeyManager.h"

Title::Title()
{
	
}

Title::~Title(){}

void Title::Draw()const
{
	DrawString(500,320,"SPASE�L�[�ŃQ�[���J�n",0xffffff);
}

void Title::Update()
{
	/*OldKey = NowKey;
	NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	KeyFlg = NowKey & ~OldKey;*/
	
	
}

AbstractScene* Title::ChangeScene()
{
	//�X�y�[�X�L�[���͂ŃQ�[���J�n
	if (KeyManager::OnKeyClicked(KEY_INPUT_SPACE))
	{
		return new GameMainScene();
	}
	return this;
}