#pragma once


#include <DxLib.h>
#include "math.h"

#define SCREEN_SIZE_X 480
#define SCREEN_SIZE_Y 480

#define BLOCK_CHIP_SIZE_X 16
#define BLOCK_CHIP_SIZE_Y 8

#define TITLE_X 50
#define TITLE_Y 0

#define BLOCK_X 40
#define BLOCK_Y 40

#define PLAYER_START_X 240
#define PLAYER_START_Y 440

#define PLAYER_SPEED 4

#define WALL_R_LINE 448
#define WALL_L_LINE 32
#define WALL_U_LINE 16


struct XY
{
	int x, y;
};




struct BLOCK
{
	int flag;
	XY pos;


	int life;

};

struct PLAYER
{
	int flag;
	XY pos;
	XY mov;

	int width;
	int height;
	float acc;
	float speed;
	float speedMax;
	int animCnt;

	int life;

	int longflag;


	int shotFlag;
	XY shotPos;
	XY shotMov;
	float shotSpeed;
	int shotCnt;

	int fallFlag;
	int fallCnt;

};



extern PLAYER ber;



void GameInit(void);
void GameOver(void);
void GameClear(void);


void PlayerImageInit(void);
void PlayerInit(void);
void PlayerMain(void);
void PlayerDraw(void);
