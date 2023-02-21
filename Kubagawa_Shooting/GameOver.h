#pragma once
#include "AbstractScene.h"
class GameOver :
    public AbstractScene
{
private:

public:
	//コンストラクタ
	GameOver();

	//デストラクタ
	virtual ~GameOver();

	//描画以外の更新を実装
	void Update() override;

	//シーンの変更処理
	virtual AbstractScene* ChangeScene() override;

	//描画に関することを実装
	void Draw() const override;

};

