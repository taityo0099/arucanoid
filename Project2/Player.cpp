#include "various.h"


PLAYER ber;



int playerImage[6];
int playerLongImage;
int fallImage;





void PlayerImageInit()
{
	LoadDivGraph("image/nomal.png", 6, 1, 6, 32, 8, playerImage);
}






void PlayerInit()
{
	ber.flag = 0;
	ber.pos.x = 240;
	ber.pos.y = 440;
	ber.mov.x = 0;
	ber.mov.y = 0;
	ber.longflag = 0;
	ber.speed = 4;
	ber.width = 32;
	ber.height = 8;
	ber.shotFlag = 0;
	ber.shotPos.x = 0;
	ber.shotPos.y = 0;

	ber.animCnt = 0;
}




void PlayerMain()
{
	int hxr = 0;	//âEx
	int hxc = 0;	//íÜâõx
	int hxl = 0;	//ç∂x
	int hyu = 0;	//è„y
	int hyc = 0;	//íÜâõy

	ber.flag = 0;



	if (CheckHitKey(KEY_INPUT_D))
	{
		ber.pos.x += ber.speed;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		ber.pos.x -= ber.speed;
	}
}



void PlayerDraw()
{
	ber.animCnt++;

	//ç≈èIìIÇ»ï`âÊ
	if (ber.flag == 0)
	{
		DrawRotaGraph(ber.pos.x, ber.pos.y, 2, 0, playerImage[ber.animCnt / 10 % 4], true);

	}

}



