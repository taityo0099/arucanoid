#pragma once

class Ball
{

public:
	Ball();
	~Ball();

	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	void SetDX(int);
	void SetDY(int);
	int GetDX();
	int GetDY();

	void Init();
	void ImageInit();
	void Move();
	void Draw();

private:
	int x, y;
	int dx, dy;
	int w, h;

	
	int normalBallImage;
	int bleakBallImage;
};

