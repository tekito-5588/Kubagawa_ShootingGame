#include "DxLib.h"
#include"SceneManager.h"
#include"GameMainScene.h"
#define WINDOW_HEIGHT 720
#define WINDOW_WHITH 1280

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {
	SetWindowSize(WINDOW_WHITH, WINDOW_HEIGHT);
	SetGraphMode(WINDOW_WHITH, WINDOW_HEIGHT, 16);

	// �^�C�g���� test �ɕύX
	SetMainWindowText("�V���[�e�B���O�Q�[��");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	DxLib_Init();

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	////�V�[���}�l�[�W���I�u�W�F�N�g�̍쐬
	//SceneManager sceneMng((AbstractScene*)new Title());
	//�V�[���}�l�[�W���I�u�W�F�N�g�̍쐬
	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()) );

	// �Q�[�����[�v
	while (ProcessMessage() == 0) {

		ClearDrawScreen();		// ��ʂ̏�����

		sceneMng.Update();      //�V�[���̍X�V����
		sceneMng.Draw();        //�V�[���̕`�揈��

		if (sceneMng.ChangeScene() == nullptr)    //�V�[���̕ύX����
		{
			DxLib_End();        //
			return 0;           //
		}
		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}