#include "play.h"

int count = 0;
bool Timer(int ms) {
	static DWORD m1, m2;
	if (m2 - m1 > ms) {
		m1 = m2;
		return true;
	}
	m2 = clock();
	return false;
}

bool Timer2(int ms) {
	static DWORD s1, s2;
	if (s2 - s1 > ms) {
		s1 = s2;
		return true;
	}
	s2 = clock();
	return false;
}

void play::init()
{
	int i = 0;
	for ( i = 0; i < ENEMY_NUM/10; i++) {
		Enemy[i] = new enemy(rand()%WIDTH, rand()%HEIGHT, 48, 64, 1,rand()%4);
	}
	for (; i < ENEMY_NUM / 2; i++) {
		Enemy[i] = new enemy(rand() % WIDTH, rand() % HEIGHT, 48, 64, 2, rand() % 4);
	}
	for (; i < ENEMY_NUM ; i++) {
		Enemy[i] = new enemy(rand() % WIDTH, rand() % HEIGHT, 48, 64, 0, rand() % 4);
	}
	for (int i = 0; i < BULL_ZERONUM; i++) {
		Bull_zero[i] = new bull(0, 0);
		Bull_one[i]= new bulll_One(0, 0);
		Bull_two[i] = new bull_tow(0, 0);
	}
	Hero = new hero(WIDTH/2, HEIGHT/2, true, 48, 64, 3);
	srand((unsigned int)time(0));
}

void Together(enemy &Enemy, bull &Bull_zero) {
	if (Bull_zero.getlive())
	{
	
	if (Bull_zero.getx() > Enemy.getx() && Bull_zero.getx() < Enemy.getx() + Enemy.getwidth()
		&& Bull_zero.gety() > Enemy.gety() && Bull_zero.gety() < Enemy.gety() + Enemy.getheight())
	{
		//Bull_zero.changelive(false);
		Enemy.changehp(Enemy.gethp() - 1);
		count++;
	}
	if (Enemy.gethp() <= 0) {
		Enemy.changelive(false);
	}
		}
}

void Together(enemy &Enemy, bulll_One &Bull_zero) {
	if (Bull_zero.getlive())
	{
		int* curx = Bull_zero.Getx();
		int* cury = Bull_zero.Gety();
		for(int i=0;i<3;i++){
			if (curx[i] > Enemy.getx() && curx[i]< Enemy.getx() + Enemy.getwidth()
				&& cury[i] > Enemy.gety() && cury[i] < Enemy.gety() + Enemy.getheight())
			{
				Bull_zero.changelive(false);
				Enemy.changehp(Enemy.gethp() - 1);
				count++;
			}
			if (Enemy.gethp() <= 0) {
				Enemy.changelive(false);
			}
		}
		
	}
}

void Together(enemy& Enemy, bull_tow& Bull_zero) {
	if (Bull_zero.getlive())
	{
		int* curx = Bull_zero.Getx();
		int* cury = Bull_zero.Gety();
		for (int i = 0; i < 8; i++) {
			if (curx[i] > Enemy.getx() && curx[i]< Enemy.getx() + Enemy.getwidth()
				&& cury[i] > Enemy.gety() && cury[i] < Enemy.gety() + Enemy.getheight())
			{
				Bull_zero.changelive(false);
				Enemy.changehp(Enemy.gethp() - 1);
				count++;
			}
			if (Enemy.gethp() <= 0) {
				Enemy.changelive(false);
			}
		}

	}
}

void Together(enemy& Enemy, hero& hero) {
	int curx = hero.getx();
	int cury = hero.gety();
	if (curx > Enemy.getx() && curx< Enemy.getx() + Enemy.getwidth()
		&& cury > Enemy.gety() && cury < Enemy.gety() + Enemy.getheight())
	{
		hero.changeHp();
		if (hero.getHp() == 0)
		{
			while (1) {
				BeginBatchDraw();
				putimage(0, 0, &bk);
				_itoa_s(count - 300, stri, 10);
				settextstyle(200, 100, "楷体");//设置字体形式（高度，宽度，字体）
				setbkmode(TRANSPARENT);//考虑到文字背景也有默认颜色，可能发生遮挡，所以将文字背景改为透明
				outtextxy(800, 350, stri);//指定位置打印字符串
				outtextxy(250, 350, "分数:");
				EndBatchDraw();
			}
		}
		//exit(0);
	}
}

void play::playTogether()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!Enemy[i]->getlive())
			continue;
		for (int k = 0; k < BULL_ZERONUM; k++) {
			Together(*Enemy[i], *Bull_zero[k]);
			Together(*Enemy[i], *Bull_one[k]);
			Together(*Enemy[i], *Bull_two[k]);
		}
		/*if (Timer2(2)) {
			Together(*Enemy[i], *Hero);
		}*/
		Together(*Enemy[i], *Hero);
	}
}

void imagetar(enemy enemy ,IMAGE *img[4][4]) {
	
		if (enemy.gettar() == 0) {
			/*
			for(int i=0;i<4;i++)
			{*/

			putimage(enemy.getx(), enemy.gety(), img[0][0]);


		}
		else if (enemy.gettar() == 1) {
			/*for (int i = 0; i < 4; i++)
			{*/
			putimage(enemy.getx(), enemy.gety(), img[0][2]);
			//}
		}
		else if (enemy.gettar() == 2) {
			/*for (int i = 0; i < 4; i++)
			{*/
			putimage(enemy.getx(), enemy.gety(), img[0][0]);
			//}
		}
		else if (enemy.gettar() == 3) {
			/*for (int i = 0; i < 4; i++)
			{*/
			putimage(enemy.getx(), enemy.gety(), img[0][1]);
			//}
		}
	
	//if (enemy.gettar() == 0) {
	//	/*
	//	for(int i=0;i<4;i++)
	//	{*/
	//	
	//		putimage(enemy.getx(), enemy.gety(), img[0][0]);
	//	
	//		
	//}
	//else if (enemy.gettar() == 1) {
	//	/*for (int i = 0; i < 4; i++)
	//	{*/
	//		putimage(enemy.getx(), enemy.gety(), img[0][2]);
	//	//}
	//}
	//else if (enemy.gettar() == 2) {
	//	/*for (int i = 0; i < 4; i++)
	//	{*/
	//		putimage(enemy.getx(), enemy.gety(), img[0][0]);
	//	//}
	//}
	//else if (enemy.gettar() == 3) {
	//	/*for (int i = 0; i < 4; i++)
	//	{*/
	//		putimage(enemy.getx(), enemy.gety(), img[0][1]);
	//	//}
	//}
}

void imagetar(hero& hero) {
	if (hero.gettar() == 0) {
		for (int i = 0; i < 4; i++) {
			putimage(hero.getx(), hero.gety(), HEro[i][3]);
		}
		
	}
	else if (hero.gettar() == 1) {
		for (int i = 0; i < 4; i++) {
			putimage(hero.getx(), hero.gety(), HEro[i][2]);
		}
	}
	else if (hero.gettar() == 2) {
		for (int i = 0; i < 4; i++) {
			putimage(hero.getx(), hero.gety(), HEro[i][0]);
		}
	}
	else if (hero.gettar() == 3) {
		for (int i = 0; i < 4; i++) {
			putimage(hero.getx(), hero.gety(), HEro[i][1]);
		}
	}
}

void imagetar(bull bull, IMAGE* img) {
	if (bull.gettar() == 0) {
		
		putimage(bull.getx()-10, bull.gety(), &img[0]);

		
	}
	else if (bull.gettar() == 1) {
		putimage(bull.getx(), bull.gety()+10, &img[1]);
	}
	else if (bull.gettar() == 2) {
		putimage(bull.getx()-10, bull.gety(), &img[2]);
	}
	else if (bull.gettar() == 3) {
		putimage(bull.getx(), bull.gety()+10, &img[3]);
	}
}//待改进，四个方位

void imagetar(bull_tow bull_two) {
	int* curx = bull_two.Getx();
	int* cury = bull_two.Gety();
	putimage(curx[0]-20, cury[0], BUll_two[0][2]);
	putimage(curx[1]-20, cury[1], BUll_two[0][3]);
	putimage(curx[2]-20, cury[2], BUll_two[0][0]);
	putimage(curx[3]-20, cury[3], BUll_two[0][1]);
	putimage(curx[4]-20, cury[4], BUll_two[0][2]);
	putimage(curx[5]-20, cury[5], BUll_two[0][3]);
	putimage(curx[6]-20, cury[6], BUll_two[0][0]);
	putimage(curx[7]-20, cury[7], BUll_two[0][1]);

	/*for (int k = 0; k < 8; k++) {
		for(int i = 0; i < 4; i++){
			putimage(curx[k], cury[k], BUll_two[i][k]);
		}
	}*/
	
}

void imagetar(bulll_One bull_one)
{
	int* curx = bull_one.Getx();
	int* cury = bull_one.Gety();
	if (bull_one.gettar() == 0)
	{
			/*for (int k = 0; k < 8; k++) {*/
				putimage(curx[0]-20, cury[0], BUll_one[0][1]);
				putimage(curx[1]-20, cury[1], BUll_one[0][2]);
				putimage(curx[2]-20, cury[2], BUll_one[0][3]);
			//}
		
	}
	else if (bull_one.gettar() == 1) {
		/*for (int k = 0; k < 8; k++) {*/
			putimage(curx[0], cury[0]+10, BUll_one[0][3]);
			putimage(curx[1], cury[1]+10, BUll_one[0][4]);
			putimage(curx[2], cury[2]+10, BUll_one[0][5]);
		//}
	}
	else if (bull_one.gettar() == 2) {
		/*for (int k = 0; k < 8; k++) {*/
			putimage(curx[0]-20, cury[0], BUll_one[0][5]);
			putimage(curx[1]-20, cury[1], BUll_one[0][6]);
			putimage(curx[2]-20, cury[2], BUll_one[0][7]);
		//}
	}
	else if (bull_one.gettar() == 3) {
		/*for (int k = 0; k < 8; k++) {*/
			putimage(curx[0], cury[0]+10, BUll_one[0][7]);
			putimage(curx[1], cury[1]+10, BUll_one[0][0]);
			putimage(curx[2], cury[2]+10, BUll_one[0][1]);
		//}
	}
}

void play::gamedraw()
{
	BeginBatchDraw();
	putimage(0, 0, &bk);
	imagetar(*Hero);
	putimage(WIDTH / 2, HEIGHT / 2, &moon);
	_itoa_s(count-300, stri, 10);
	settextstyle(20, 0, "楷体");//设置字体形式（高度，宽度，字体）
	setbkmode(TRANSPARENT);//考虑到文字背景也有默认颜色，可能发生遮挡，所以将文字背景改为透明
	outtextxy(100, 100, stri);//指定位置打印字符串
	outtextxy(50, 100, "分数:");
	
	//EndBatchDraw();

	//BeginBatchDraw();
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (Enemy[i]->getlive())
		{
			if (Enemy[i]->getType() == 0)//为什么敌人的type都是0
				imagetar(*Enemy[i], ENemy0);
			else if (Enemy[i]->getType() == 1)
				imagetar(*Enemy[i], ENemy1);
			else
				imagetar(*Enemy[i], ENemy2);
		}
	}
	//EndBatchDraw();

	//BeginBatchDraw();
	for (int i = 0; i < BULL_ZERONUM; i++) {
		if (Bull_zero[i]->getlive()) {
			imagetar(*Bull_zero[i], BUll_zero);
			
		}
	}
	//EndBatchDraw();

	//BeginBatchDraw();
	for (int i = 0; i < BULL_ONENUM; i++) {
		if (Bull_one[i]->getlive()) {
			imagetar(*Bull_one[i]);
			
		}
	}
	//EndBatchDraw();

	//BeginBatchDraw();
	for (int i = 0; i < BULL_ONENUM; i++) {
		if (Bull_two[i]->getlive()) {
			imagetar(*Bull_two[i]);
			
		}
	}
	
	EndBatchDraw();
}

void play::Loadimage()
{
	if (ENemy0[0][0] == NULL) {
		//切块图片
		IMAGE imaTmp;
		loadimage(&imaTmp, "./Enemy0.png");//在属性->高级->字符集->改成多字符集
		SetWorkingImage(&imaTmp);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				ENemy0[i][j] = new IMAGE;
				getimage(ENemy0[i][j], i * 48, j * 64, 48, 64);
			}
		}
		SetWorkingImage();//恢复工作区
	}

	if (ENemy1[0][0] == NULL) {
		//切块图片
		IMAGE imaTmp;
		loadimage(&imaTmp, "./Enemy1.png");//在属性->高级->字符集->改成多字符集
		SetWorkingImage(&imaTmp);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				ENemy1[i][j] = new IMAGE;
				getimage(ENemy1[i][j], i * 48, j * 64, 48, 64);
			}
		}
		SetWorkingImage();//恢复工作区
	}

	if (ENemy2[0][0] == NULL) {
		//切块图片
		IMAGE imaTmp;
		loadimage(&imaTmp, "./Enemy2.png");//在属性->高级->字符集->改成多字符集
		SetWorkingImage(&imaTmp);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				ENemy2[i][j] = new IMAGE;
				getimage(ENemy2[i][j], i * 48, j * 64, 48, 64);
			}
		}
		SetWorkingImage();//恢复工作区
	}

	if (HEro[0][0] == NULL) {
		//切块图片
		IMAGE imaTmp;
		loadimage(&imaTmp, "./Hero.png" );
		SetWorkingImage(&imaTmp);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				HEro[i][j] = new IMAGE;
				//getimage(HEro[i][j], i * 64, j * 48, 64, 48);
				getimage(HEro[i][j], i * 48, j * 64, 48, 64);
			}
		}
		SetWorkingImage();//恢复工作区
	}

	if (BUll_two[0][0] == NULL) {
		//切块图片
		IMAGE imaTmp;
		loadimage(&imaTmp, "./bull2.png");//在属性->高级->字符集->改成多字符集
		SetWorkingImage(&imaTmp);
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 8; i++) {
				BUll_two[i][j] = new IMAGE;
				getimage(BUll_two[i][j], i * 64, j * 64, 64, 64);
			}
		}
		SetWorkingImage();//恢复工作区
	}

	if (BUll_one[0][0] == NULL) {
		//切块图片
		IMAGE imaTmp;
		loadimage(&imaTmp, "./bull1.png");//在属性->高级->字符集->改成多字符集
		SetWorkingImage(&imaTmp);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				BUll_one[i][j] = new IMAGE;
				getimage(BUll_one[i][j], i * 64, j * 64, 64, 64);
			}
		}
		SetWorkingImage();//恢复工作区
	}

	loadimage(&bk,"./bk.jpg");
	loadimage(&BUll_zero[0],"./bull00.png");
	loadimage(&BUll_zero[1],"./bull01.png" );
	loadimage(&BUll_zero[2], "./bull02.png");
	loadimage(&BUll_zero[3], "./bull03.png");
	loadimage(&moon, "/moon.gif");
	//loadimage(&BUll_zero[3],"./bull04.png" );

}

void play::creatEnemy()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (!Enemy[i]->getlive())
		{
			Enemy[i]->changelive(true);
			
			//修改敌人的位置
			Enemy[i]->changetar(rand() % WIDTH, rand() % HEIGHT);
			int m = rand() % 10;
			if (m > 7) {
				Enemy[i]->changeType(2);
			}
			else if (m >= 5)
			{
				Enemy[i]->changeType(1);
			}
			else {
				Enemy[i]->changeType(0);
			}
		}
	}
}

void play::ceratBull(int type)
{
	if (type == 0) {
		for (int i = 0; i < BULL_ZERONUM; i++) {
			if (!Bull_zero[i]->getlive()) {
				Bull_zero[i]->changetar(Hero->gettar());
				Bull_zero[i]->changetar(Hero->getx() + 20, Hero->gety());;
				Bull_zero[i]->changelive(true);
				break;
			}
		}
	}
	else if (type == 1) {
		for (int i = 0; i < BULL_ZERONUM; i++) {
			if (!Bull_one[i]->getlive()) {
				Bull_one[i]->changetar(Hero->gettar());
				Bull_one[i]->changetar(Hero->getx() + 20, Hero->gety());;
				Bull_one[i]->changelive(true);
				break;
			}
		}
	}
	else {
		for (int i = 0; i < BULL_ZERONUM; i++) {
			if (!Bull_two[i]->getlive()) {
				Bull_two[i]->changetar(Hero->gettar());
				Bull_two[i]->changexy(Hero->getx() + 20, Hero->gety());
				Bull_two[i]->changelive(true);
				break;
			}
		}
	}
	
	
}

void play::keyboard(int speed)
{
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (Hero->gety() > 0)
		{
			Hero->changetar(0);
			Hero->changey(Hero->gety() - speed);
		}
		if (Hero->gety()  <=0) {
			Hero->changey(HEIGHT-64);
		}
	}
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('S'))
	{
		if (Hero->gety() +64 < HEIGHT)
		{
			Hero->changetar(2);
			Hero->changey(Hero->gety() + speed);
		}
		if (Hero->gety() + 64 >= HEIGHT) {
			Hero->changey(0);
		}
	}
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('A'))
	{
		if (Hero->getx() > 0)
		{
			Hero->changetar(3);
			Hero->changex(Hero->getx() - speed);
		}
		if (Hero->getx() <=0) {
			Hero->changex(WIDTH-64);
		}
	}
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('D'))
	{
		if (Hero->getx() + 64 < WIDTH)//图片高度
		{
			Hero->changetar(1);
			Hero->changex(Hero->getx() + speed);
		}
		if (Hero->getx() + 64 >= WIDTH) {
			Hero->changex(0);
		}
	}

	if (GetAsyncKeyState('K'))
	{
		bulltype++;
		bulltype %= 3;
	}

	static DWORD t1 = 0, t2 = 0;
	if (GetAsyncKeyState('J') && t2 - t1 > 100)
	{
		//创建一个子弹
		play::ceratBull(bulltype);
		printf("buultype::%d\n", bulltype);
		t1 = t2;
	}
	MoveBull(4);
	t2 = GetTickCount();

}

void play::MoveBull(int speed)
{
	for (int i = 0; i < BULL_ZERONUM; i++) {
		if (Bull_zero[i]->getlive()) {
			Bull_zero[i]->move(speed);
		}
		if (Bull_one[i]->getlive()) {
			Bull_one[i]->move(speed);
		}
		if (Bull_two[i]->getlive()) {
			Bull_two[i]->move(speed);
		}
	}
}


void play::EnemyMove(int speed)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (Enemy[i]->getlive()) {
			Enemy[i]->move(Hero->getx(), Hero->gety());
			//if (Enemy[i]->getType() == 2) {
			//	if ((Enemy[i]->getx() == WIDTH / 2) && (Enemy[i]->gety() == HEIGHT / 2))
			//	{
			//		while (1) {
			//			BeginBatchDraw();
			//			putimage(0, 0, &bk);
			//			_itoa_s(count - 300, stri, 10);
			//			settextstyle(200, 100, "楷体");//设置字体形式（高度，宽度，字体）
			//			setbkmode(TRANSPARENT);//考虑到文字背景也有默认颜色，可能发生遮挡，所以将文字背景改为透明
			//			outtextxy(800, 350, stri);//指定位置打印字符串
			//			outtextxy(250, 350, "分数:");
			//			EndBatchDraw();
			//		}
			//	}
			//}
		}
	}
}




int main() {
	play game;
	

	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
	//loadimage(&bk, "./bk.png");
	putimage(0, 0, &bk);
	game.init();
	game.Loadimage();
	while (1) {
		
		game.gamedraw();
		FlushBatchDraw();
		game.keyboard(3);
		//game.MoveBull(2);
		if (Timer(10)) {
			game.creatEnemy();
		}
		game.EnemyMove(2);
		game.playTogether();
	}
}
//enemy* Enem[2];
//int main() {
//	if (BUll_one[0][0] == NULL) {
//		//切块图片
//		IMAGE imaTmp;
//		loadimage(&imaTmp, "./bull1.png");//在属性->高级->字符集->改成多字符集
//		SetWorkingImage(&imaTmp);
//		for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++) {
//				BUll_one[i][j] = new IMAGE;
//				getimage(BUll_one[i][j], i * 64, j * 64, 64, 64);
//			}
//		}
//		SetWorkingImage();//恢复工作区
//	}
//	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
//	while (1) {
//		
//		for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++) {
//				putimage(i * 60, +j * 60, BUll_one[i][j]);
//			}
//		}
//	}
//	
//}