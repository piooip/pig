
//bool Timer(int ms) {
//	static DWORD m1, m2;
//	if (m2 - m1 > ms) {
//		m1 = m2;
//		return true;
//	}
//	m2 = clock();
//	return false;
//}
//int main() {
//	play game;
//	while (1) {
//		game.gamedraw();
//		FlushBatchDraw();
//		game.keyboard(1);
//		game.MoveBull(2);
//		if (Timer(500)) {
//			game.creatEnemy();
//		}
//		game.EnemyMove(1);
//		game.playTogether();
//	}
//}

