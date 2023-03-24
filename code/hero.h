#pragma once
#include"bace.h"
#include"bull.h"

class hero : public bace 
{
public:
	hero(int x, int y,bool live,int width,int height,int hp);

	int getx();
	int gety();
	void changex(int x);
	void changey(int y);
	int gettar();
	void changetar(int tar);
	void Draw();
	int getHp();
	void changeHp();
private:
	int _tar;
	int _x;
	int _y;
	bool _live;
	int _width;
	int _height;
	int _hp;

};

