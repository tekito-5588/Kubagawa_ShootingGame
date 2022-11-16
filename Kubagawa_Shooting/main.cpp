#include "DxLib.h"
#include"SceneManager.h"
#include"GameMainScene.h"
#define WINDOW_HEIGHT 720
#define WINDOW_WHITH 1280

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {
	SetWindowSize(WINDOW_WHITH, WINDOW_HEIGHT);
	SetGraphMode(WINDOW_WHITH, WINDOW_HEIGHT, 16);

	// タイトルを test に変更
	SetMainWindowText("シューティングゲーム");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	DxLib_Init();

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	////シーンマネージャオブジェクトの作成
	//SceneManager sceneMng((AbstractScene*)new Title());
	//シーンマネージャオブジェクトの作成
	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()) );

	// ゲームループ
	while (ProcessMessage() == 0) {

		ClearDrawScreen();		// 画面の初期化

		sceneMng.Update();      //シーンの更新処理
		sceneMng.Draw();        //シーンの描画処理

		if (sceneMng.ChangeScene() == nullptr)    //シーンの変更処理
		{
			DxLib_End();        //
			return 0;           //
		}
		ScreenFlip();			// 裏画面の内容を表画面に反映
	}

	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}