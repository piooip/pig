#pragma once
#include "bull.h"
class bulll_One :public bull
{
public:
	bulll_One(int x, int y);
	 virtual void move(int speed);

	 int* Getx();
	 int* Gety();
	 virtual void changetar(int x, int y);
	 void changetar(int tar);
private:
	int _x[3];
	int _y[3];
	
	//int _width;
	//int _height;
	//bool _live;
	//int _type;
	//IMAGE Bull_one;
};

