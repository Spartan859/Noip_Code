#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n, number;
	bool win = false;
	// 随机生成一个整数
	srand(0);  // 初始化随机数发生器 
	number = rand() % 50;
	//cout << number << endl; // 显示随机数 
	cout << "Please guess a number." << endl;
	int i = 1; 
	while (i <= 5) {
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
	return 0;	
} 
