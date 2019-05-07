#include "block.h"
#include "various.h"


block::block()
{
}


block::~block()
{
}

void block::Init()
{
	ImageInit();

	x = 0;
	y = 0;

	w = 16;
	h = 8;

}

void block::ImageInit()
{
	LoadDivGraph("image/block.png", 20, 5, 4, 16, 8, blockImage);
	LoadDivGraph("image/blockbreak.png", 5, 5, 1, 16, 8, blockAnimImage);
}

void block::Draw()
{

	
	
	DrawRotaGraph(x+w, y+h, 2, 0, blockImage[1], true);
	
	/*DrawLine(WALL_R_LINE, WALL_U_LINE, WALL_R_LINE, SCREEN_SIZE_Y, 0xff0000, true);
	DrawLine(WALL_L_LINE, WALL_U_LINE, WALL_L_LINE, SCREEN_SIZE_Y, 0xff0000, true);
	DrawLine(WALL_U_LINE, WALL_U_LINE, WALL_R_LINE, WALL_U_LINE, 0xff0000, true);*/
}

void block::SetPos(int x, int y)
{
	this->x = x;
	this->y = y;
}
