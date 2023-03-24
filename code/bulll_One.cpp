#include "bulll_One.h"

bulll_One::bulll_One(int x, int y)
	:bull(x, y)
{
	for (int i = 0; i < 3; i++) {
		_x[i] = x;
	}
	for (int i = 0; i < 3; i++) {
		_y[i] = y;
	}
	
	_live = true;

}

void bulll_One::move( int speed)
{

	if (_live) {
		if (_tar == 0)
		{
			for (int i = 0; i < 3; i++) {
				_y[i] -= speed;
			}
			_x[0] -= speed;
			_x[2] += speed;
		}
		else if (_tar == 1) {
			for (int i = 0; i < 3; i++) {
				_x[i] += speed;
			}
			_y[0] -= speed;
			_y[2] += speed;
		}
		else if (_tar == 2) {
			for (int i = 0; i < 3; i++) {
				_y[i] += speed;
			}
			_x[0] += speed;
			_x[2] -= speed;
		}
		else if (_tar == 3) {
			for (int i = 0; i < 3; i++) {
				_x[i] -= speed;
			}
			_y[0] += speed;
			_y[2] -= speed;
		}
		for (int i = 0; i < 3; i++) {
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

}



int* bulll_One::Getx()
{

	return _x;
}

int* bulll_One::Gety()
{
	return _y;
}

void bulll_One::changetar(int tar)
{
	_tar = tar;
}

void bulll_One::changetar(int x, int y)
{
	for (int i = 0; i < 3; i++) {
		_x[i] = x;
	}
	for (int i = 0; i < 3; i++) {
		_y[i] = y;
	}
}
