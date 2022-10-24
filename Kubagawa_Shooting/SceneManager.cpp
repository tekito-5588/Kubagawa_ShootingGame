#include"DxLib.h"
#include "SceneManager.h"
#include"AbstractScene.h"
#include"KeyManager.h"

void SceneManager::Update()
{
	KeyManager::Update();

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