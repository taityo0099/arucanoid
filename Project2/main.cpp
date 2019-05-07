#include "various.h"
#include "Ball.h"
#include "block.h"

enum GAME_MODE
{
	GMODE_INIT,
	GMODE_TITLE,
	GMODE_GAME,
	GMODE_PAUSE,
	GMODE_CLEAR,
	GMODE_OVER,
	GMODE_MAX
};

GAME_MODE gameMode;

int bgImage[9];

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	SetWindowText("Arkanoid 1701323	‘å’·");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);


	//²Ò°¼Þ
	gameMode = GMODE_INIT;
	Ball *ball;
	ball = new Ball;

	block *obj[6][11];
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 11; x++)
		{
			obj[y][x] = new block();
		}
	}	

	//BgImageInit();
	
	//BallImageInit();

	GameInit();


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();

		switch (gameMode) {
		case GMODE_INIT:
			gameMode = GMODE_TITLE;
			PlayerInit();
			ball->Init();
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 11; x++)
				{
					obj[y][x]->Init();
					obj[y][x]->SetPos(64 + x * 2 * obj[0][0]->GetW(),64 + y * 2 * obj[0][0]->GetH());
				}
			}

			DrawString(0, 0, "INIT", 0xffff00, true);

			break;

		case GMODE_TITLE:

			DrawString(SCREEN_SIZE_X / 2 - TITLE_X, SCREEN_SIZE_Y / 2, "PUSH SPACE", 0xffffff, true);
			if (CheckHitKey(KEY_INPUT_SPACE))
			{
				gameMode = GMODE_GAME;

			}
			//DrawString(0, 0, "TITLE", 0xffff00, true);
			break;
		case GMODE_GAME:
			PlayerMain();
			ball->Move();
			
			//BgDraw();
			DrawRotaGraph(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, 2, 0, bgImage[0], true);
			ball->Draw();
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 11; x++)
				{
					obj[y][x]->Draw();
				}
			}
			PlayerDraw();
			
			break;
		}

		DxLib::ScreenFlip();
	}
	delete ball;
	ball = nullptr;
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 11; x++)
		{
			delete obj[y][x];
			obj[y][x] = nullptr;
		}
	}
	DxLib_End();
	return 0;
}


void GameInit()
{
	LoadDivGraph("image/Fields.png", 9, 5, 2, 224, 238, bgImage);
	PlayerImageInit();
	
}

void GameOver()
{

}

void GameClear()
{

}
