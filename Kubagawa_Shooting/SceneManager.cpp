#include"DxLib.h"
#include "SceneManager.h"
#include"AbstractScene.h"

void SceneManager::Update()
{
	//���݃V�[���̃A�b�v�f�[�g�����s
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