#pragma once
#include "bace.h"
#include<time.h>
#include<stdio.h>
#include<conio.h>
class enemy:public bace
{
public:
	enemy(int x, int y, int width, int height,int type,int tar);
	virtual void move(int hero_x, int hero_y);

	void enemyHp(int i);
	bool getlive();
	void changetar(int x, int y);
	void changelive(bool live);
	void changeType(int i);
	int getType();
	int gethp();
	void changehp(int hp);
	int getwidth();
	int getheight();
	int getx();
	int gety();
	int gettar();


private:
	int _x;
	int _y;
	int _hp = 2;
	bool _live;
	int _width;
	int _height;
	int _type;
	int k=0;
	int _tar;
	//IMAGE Enemy();
	
};

