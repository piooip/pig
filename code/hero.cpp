#include "hero.h"

hero::hero(int x, int y, bool live, int width, int height, int hp)
	:bace()
	, _x(x)
	, _y(y)
	, _live(true)
	, _width(width)
	, _height(height)
	, _hp(hp)
	,_tar(0)
{
	
	
}

//void hero::move(int speed)
//{
//	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
//	{
//		if (_y > 0)
//		{
//			_y -= speed;
//			_tar = 0;
//		}
//
//	}
//	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('S'))
//	{
//		if (_y + 120 < HEIGHT)
//		{
//			_y += speed;
//			_tar = 2;
//		}
//	}
//	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('A'))
//	{
//		if (_x > 0)
//		{
//			_x -= speed;
//			_tar = 3;
//		}
//	}
//	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('X'))
//	{
//		if (_x + 117 < WIDTH)//图片高度
//		{
//			_x += speed;
//			_tar = 1;
//		}
//	}
//	static DWORD t1 = 0, t2 = 0;
//	if (GetAsyncKeyState(VK_SPACE) && t2 - t1 > 50)
//	{
//		//创建一个子弹
//		play::ceratBull();
//		t1 = t2;
//	}
//	t2 = GetTickCount();
//}

int hero::getx()
{
	return _x;
}

int hero::gety()
{
	return _y;
}

void hero::changex(int x)
{
	_x = x;
}

void hero::changey(int y)
{
	_y = y;
}

int hero::gettar()
{
	return _tar;
}

void hero::changetar(int tar)
{
	_tar = tar;
}

int hero::getHp()
{
	return _hp;
}

void hero::changeHp()
{
	_hp--;
}



