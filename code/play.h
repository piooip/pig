#pragma once
#include"bull.h"
#include"enemy.h"
#include"hero.h"
#include"bulll_One.h"
#include"bull_tow.h"
#include<time.h>
#include<stdio.h>
#include<conio.h>
#define ENEMY_NUM 50
#define BULL_ZERONUM 300
#define BULL_ONENUM 300

IMAGE moon;
IMAGE bk;
IMAGE BUll_zero[5];
IMAGE* BUll_two[8][4];
IMAGE *BUll_one[8][8];
IMAGE *ENemy0[4][4];
IMAGE* ENemy1[4][4];
IMAGE* ENemy2[4][4];
IMAGE* HEro[4][4];

enemy *Enemy[ENEMY_NUM];
hero *Hero;
bull *Bull_zero[BULL_ZERONUM];
bulll_One *Bull_one[BULL_ONENUM];
bull_tow* Bull_two[BULL_ONENUM];

int bulltype = 0;

//int count = 0;
char stri[7];

class play
{
public:
	void init();
	void playTogether();
	void gamedraw();
	void Loadimage();
	void creatEnemy();
	void ceratBull(int type);
	void keyboard(int speed);
	void MoveBull(int speed);
	void EnemyMove(int speed);
	//bool Timer(int ms);
	

private:
	//IMAGE bk;
	//IMAGE BUll_zero[5];
	//IMAGE* BUll_two[8][4];
	//IMAGE* BUll_one[8][8];
	//IMAGE* ENemy0[4][4];
	//IMAGE* ENemy1[4][4];
	//IMAGE* ENemy2[4][4];
	//IMAGE* HEro[4][4];

	//enemy* Enemy[ENEMY_NUM];
	//hero* Hero;
	//bull* Bull_zero[BULL_ZERONUM];
	//bulll_One* Bull_one[BULL_ONENUM];
	//bull_tow* Bull_two[BULL_ONENUM];

	int bulltype = 0;
};

