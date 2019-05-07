#include "Ball.h"
#include "various.h"

Ball::Ball()
{
}


Ball::~Ball()
{
}



void Ball::Init()
{
	ImageInit();
	GetGraphSize(normalBallImage, &w, &h);

	x = ber.pos.x + ber.width / 2;
	y = ber.pos.y - 16;

	dx = 3;
	dy = -3;

	ImageInit();
}

void Ball::ImageInit()
{
	normalBallImage = LoadGraph("image/ball.png");
	bleakBallImage = LoadGraph("image/bleakball.png");
}


void Ball:: Move()
{
	x += dx;
	y += dy;

	if (x > WALL_R_LINE)
	{
		x = WALL_R_LINE;
		dx *= -1;
	}
	if (x < WALL_L_LINE)
	{
		x = WALL_L_LINE;
		dx *= -1;
	}
	if (y < WALL_U_LINE)
	{
		y = WALL_U_LINE;
		dy *= -1;
	}
	
}
int Ball::GetX()
{
	return x;
}

int Ball::GetY()
{
	return y;
}

int Ball::GetWidth()
{
	return w;
}

int Ball::GetHeight()
{
	return h;
}

void Ball::SetDX(int x)
{
	dx = x;
}

void Ball::SetDY(int y)
{
	dy = y;
}

int Ball::GetDX()
{
	return dx;
}

int Ball::GetDY()
{
	return dy;
}

void Ball:: Draw()
{
	DrawRotaGraph(x, y, 2, 0, normalBallImage, true);
}