#pragma once
#include<graphics.h>
#define WIDTH 1280
#define HEIGHT 1024
//int count = 0;

class bace
{
public:
	void move();
	void Create_it();
	int getx();
	int gety();
	void changex(int x);
	void changey(int y);
	int gettar();
	void changetar(int tar);
};

