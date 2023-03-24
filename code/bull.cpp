#include "bull.h"

bull::bull(int x, int y)
{
	_live = true;
	_x = x;
	_y = y;
	it = 0;

}

void bull::move(int speed)
{

	if (_live) {
		if(_tar==0)
		{
			_y -= speed;
		}
		else if (_tar == 1) {
			_x += speed;
		}
		else if (_tar == 2) {
			_y += speed;
		}
		else if (_tar == 3) {
			_x -= speed;
		}

		//if (_y < 0)
		//{
		//	_y = HEIGHT;
		//}
		//if (_y > HEIGHT)
		//{
		//	_y = 0;ddd
		//}
		//if (_x < 0)
		//{
		//	_x = WIDTH;
		//}
		//else if (_x > WIDTH)
		//{
		//	_x = 0;
		//}
		if (_y < 0 || _y>HEIGHT || _x<0 || _x>WHITE)
		{
			_live = false;
		}
	}
}


int bull::getlive()
{
	return _live;
}

void bull::changetar(int tar)
{
	_tar = tar;
}



void bull::changelive(int live)
{
	_live = live;
}

void bull::changetar(int x, int y)
{
	_x = x;
	_y = y;
}

int bull::getx()
{
	return _x;
}

int bull::gety()
{
	return _y;
}

int bull::gettar()
{
	return _tar;
}

int bull::getit()
{
	return it;
}

void bull::changeit()
{
	it = 1;
}

