#include "enemy.h"

enemy::enemy(int x, int y,  int width, int height, int type,int tar)
{
	_x = x;
	_y = y;
	_live = false;
	_width = width;
	_height = height;
	_type = type;
	_tar = tar;
	k = 0;
	//k = rand() % 10;
	if (type == 0)
		_hp = 1;
	else if(type == 1)
		_hp = 1;
	else
		_hp = 1;
	
}

bool Timer1(int ms) {
	static DWORD s1, s2;
	if (s2 - s1 > ms) {
		s1 = s2;
		return true;
	}
	s2 = clock();
	return false;
}


void enemy::move(int hero_x,int hero_y)
{
	//第一种情况
	srand(time(NULL));
	//if (_y < 0 || _y>HEIGHT || _x<0 || _x>WHITE)
	//{
	//	_live = false;
	//}

		if (_live == true && _type == 0) {
			if(k%2==0){
				if (hero_x > _x)
				{
					_tar = 1;
					_x++;
				}
				else {
					_tar = 3;
					_x--;
				}
				k++;
			}
			else{
				if (hero_y > _y) {
					_tar = 2;
					_y++;
				}
				else {
					_tar = 0;
					_y--;
				}
				k++;
			}
			
			//处理超过边框的情况
		}
	

		//第二种情况
		if (_live == true && _type == 1)
		{
			srand(time(NULL));
			if (Timer1(500)) {
			_x = rand() % WIDTH;
			_y = rand() % HEIGHT;
			}
		}
	
		//有问题
		if (_live == true && _type == 2)
		{
			/*srand(time(NULL));
			int m = rand() % 2;
			int n = rand() % 2;
			if (rand() % 4==0)
			{
				_x = _x + n;
				_y = _y + m;
			}
			else if (rand() % 4 == 1)
			{
				_x = _x - n;
				_y = _y - m;
			}
			else if (rand() % 4 == 2)
			{
				_x = _x - n;
				_y = _y + m;
			}
			else {
				_x = _x + n;
				_y = _y - m;
			}*/
			int m = rand() % 9;
			if (m > 5) {
				if (_x >  WIDTH/2)
					_x--;
				else
					_x++;
			}
			else {
				if (_y > HEIGHT / 2)
					_y--;
				else
					_y++;
			}
			
		}
		/*if (_y < 0)
		{
			_y = HEIGHT;
		}
		if (_y > HEIGHT)
		{
			_y = 0;
		}
		if (_x < 0)
		{
			_x = WIDTH;
		}
		else if(_x>WIDTH)
		{
			_x = 0;
		}*/
		if (_y < 0)
			_y = HEIGHT;
		if (_y > HEIGHT)
			_y = 0;
		if (_x < 0)
			_x = WIDTH;
		else if (_x > WIDTH)
			_x = 0;

	
	/*if (_y < 0 || _y>HEIGHT || _x<0 || _x>WHITE)
	{
		_live = false;
	}*/
}




void enemy::enemyHp(int i)
{

}

bool enemy::getlive()
{
	return _live;
}

void enemy::changetar(int x, int y)
{
	_x = x;
	_y = y;
}

void enemy::changelive(bool live)
{
	_live = live;
}

void enemy::changeType(int i)
{
	_type = i;
	if (i == 0)
		_hp = 1;
	else if (i == 1)
		_hp = 2;
	else
		_hp = 3;
}

int enemy::getType()
{
	return _type;
}

int enemy::gethp()
{
	return _hp;
}

void enemy::changehp(int hp)
{
	_hp = hp;
}

int enemy::getwidth()
{
	return _width;
}

int enemy::getheight()
{
	return _height;
}

int enemy::getx()
{
	return _x;
}

int enemy::gety()
{
	return _y;
}

int enemy::gettar()
{
	return _tar;
}
