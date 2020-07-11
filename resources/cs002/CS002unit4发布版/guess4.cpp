#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n, number;
	// 随机生成一个整数
	srand(0);  // 初始化随机数发生器 
	while (true) {
		bool win = false;
		// 打印欢迎信息 
		cout << "********************************************" << endl; 
		cout << "* Welcome to David's guessing number game! *" << endl;
		cout << "********************************************" << endl; 
		number = rand() % 50;
		cout << number << endl; // 显示随机数 
		int i = 1; 
		while (i <= 5) {
			if (win)
				break;
			cout << "Please guess a number." << endl;
			if (!win) {
				cin >> n;
				if (n > number)  // 如果猜的数字大了 
					cout << "Your guess is bigger than the number." << endl;
				else if (n < number) // 如果猜的数字小了
					cout << "Your guess is smaller than the number." << endl;
				else {  // 成功猜对数字 
					cout << "You win. The number is " << number << endl;
					win = true;
				}
			}
			i++;
		} 
		if (win)
			cout << "You win in " << i - 1 << " guesses." << endl;
		cout << endl;
		// 询问是否结束游戏 
		cout << "Play another round? Press y for yes, n for no." << endl;
		char stopgame;
		cin >> stopgame; 
		if (stopgame == 'y' || stopgame == 'Y')
			break;
	}

	return 0;	
} 
