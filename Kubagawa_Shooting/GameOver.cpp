#include"DxLib.h"
#include "GameOver.h"
#include "Title.h"
#include"KeyManager.h"
#include"GameMainScene.h"

GameOver::GameOver(){}

GameOver::~GameOver(){}

void GameOver::Draw() const
{
	DrawString(500, 320, "GAME OVER", 0xffffff);
	DrawString(460, 400, "ENTER��TITLE�ɖ߂�", 0xffffff);
}

void GameOver::Update()
{

}

AbstractScene* GameOver::ChangeScene()
{
	//�X�y�[�X�L�[���͂ŃQ�[���J�n
	if (KeyManager::OnKeyClicked(KEY_INPUT_RETURN))
	{
		return new Title();
	}
	return this;
}