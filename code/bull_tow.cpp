#include "bull_tow.h"



bull_tow::bull_tow(int x, int y)
	:bull(x, y)
{
	for (int i = 0; i < 8; i++) {
		_x[i] = x;
	}
	for (int i = 0; i < 8; i++) {
		_y[i] = y;
	}

	_live = false;
}


void bull_tow::move( int speed)
{
		_y[0] -= speed;
		_x[1] += speed;
		_y[1] -= speed;
		_x[2] += speed;
		_x[3] += speed;
		_y[3] += speed;
		_y[4] += speed;
		_x[5] -= speed;
		_y[5] += speed;
		_x[6] -= speed;
		_x[7] -= speed;
		_y[7] -=speed ;
		for (int i = 0; i < 8; i++) {
			/*if (_y[i] < 0 || _y[i]>HEIGHT || _x[i]<0 || _x[i]>WHITE)
			{
				_live = false;
			}*/
			if (_y[i] < 0)
			{
				_y[i] = HEIGHT;
			}
			if (_y[i] > HEIGHT)
			{
				_y[i] = 0;
			}
			if (_x[i] < 0)
			{
				_x[i] = WIDTH;
			}
			else if (_x[i] > WIDTH)
			{
				_x[i] = 0;
			}
		}
		
}

int* bull_tow::Getx()
{
	return _x;
}

int* bull_tow::Gety()
{
	return _y;
}

void bull_tow::changexy(int x, int y)
{
	for (int i = 0; i < 8; i++) {
		_x[i] = x;
	}
	for (int i = 0; i < 8; i++) {
		_y[i] = y;
	}
}

void bull_tow::changetar(int tar)
{
	_tar = tar;
}
