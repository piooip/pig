#pragma once
#include"bull.h"
class bull_tow :public bull
{
public:
	bull_tow(int x, int y);
	virtual void move( int speed);

	int* Getx();
	int* Gety();
	virtual void changexy(int x, int y);
	void changetar(int tar);
private:
	int _x[8];
	int _y[8];
	
	//IMAGE Bull_two;
};

