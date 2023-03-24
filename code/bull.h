#pragma once
#include"bace.h"

class bull 
{
public:
	bull(int x=0, int y=0);
	virtual void move(int speed);

	int getlive();
	void changetar(int tar);
	void changelive(int live);
	virtual void changetar(int x, int y);
	virtual int getx();
	virtual int gety();
	int gettar();
	int getit();
	void changeit();
protected:
	int _tar=0;
	int _x=0;
	int _y=0;
	bool _live=false;
	int it=0;
	//int _live = false;
	//int _type;

};

