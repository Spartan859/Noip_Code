#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n, number;
	// �������һ������
	srand(0);  // ��ʼ������������� 
	while (true) {
		bool win = false;
		// ��ӡ��ӭ��Ϣ 
		cout << "********************************************" << endl; 
		cout << "* Welcome to David's guessing number game! *" << endl;
		cout << "********************************************" << endl; 
		number = rand() % 50;
		cout << number << endl; // ��ʾ����� 
		int i = 1; 
		while (i <= 5) {
			if (win)
				break;
			cout << "Please guess a number." << endl;
			if (!win) {
				cin >> n;
				if (n > number)  // ����µ����ִ��� 
					cout << "Your guess is bigger than the number." << endl;
				else if (n < number) // ����µ�����С��
					cout << "Your guess is smaller than the number." << endl;
				else {  // �ɹ��¶����� 
					cout << "You win. The number is " << number << endl;
					win = true;
				}
			}
			i++;
		} 
		if (win)
			cout << "You win in " << i - 1 << " guesses." << endl;
		cout << endl;
		// ѯ���Ƿ������Ϸ 
		cout << "Play another round? Press y for yes, n for no." << endl;
		char stopgame;
		cin >> stopgame; 
		if (stopgame == 'y' || stopgame == 'Y')
			break;
	}

	return 0;	
} 
