#include"DxLib.h"
#include "SceneManager.h"
#include"AbstractScene.h"
#include"KeyManager.h"

void SceneManager::Update()
{
	KeyManager::Update();

	//現在シーンのアップデートを実行
	mScene->Update();
}
void SceneManager::Draw() const
{
	mScene->Draw();
}

AbstractScene* SceneManager::ChangeScene()
{
	AbstractScene* nextScene = mScene->ChangeScene();

	if (nextScene != mScene)
	{
		delete mScene;
		mScene = nextScene;

		return nextScene;
	}
}