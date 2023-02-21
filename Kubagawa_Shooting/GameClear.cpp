#include"DxLib.h"
#include"Title.h"
#include"GameClear.h"
#include"Enemy.h"
#include"KeyManager.h"
#include"GameMainScene.h"

GameClear::GameClear()
{

}

GameClear::~GameClear(){}

void GameClear::Draw() const
{
	DrawString(500, 320, "GAME CLEAR", 0xffffff);
	DrawString(460, 400, "ENTER��TITLE�ɖ߂�", 0xffffff);
}

void GameClear::Update()
{

}

AbstractScene* GameClear::ChangeScene()
{
	//�X�y�[�X�L�[���͂ŃQ�[���J�n
	if (KeyManager::OnKeyClicked(KEY_INPUT_RETURN))
	{
		return new Title();
	}
	return this;
}