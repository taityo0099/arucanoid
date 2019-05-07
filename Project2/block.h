#pragma once
class block
{
public:
	block();
	~block();

	void Init();
	void ImageInit();
	void Draw();

	int GetW(void) { return w; };
	int GetH(void) { return h; };
	void SetPos(int, int);

private:
	int x, y;
	int w, h;
	

	int blockImage[20];
	int blockAnimImage[5];
	
};

