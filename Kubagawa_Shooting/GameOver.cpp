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
	DrawString(460, 400, "ENTERでTITLEに戻る", 0xffffff);
}

void GameOver::Update()
{

}

AbstractScene* GameOver::ChangeScene()
{
	//スペースキー入力でゲーム開始
	if (KeyManager::OnKeyClicked(KEY_INPUT_RETURN))
	{
		return new Title();
	}
	return this;
}