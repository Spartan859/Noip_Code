#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n, number;
	bool win = false;
	// �������һ������
	srand(0);  // ��ʼ������������� 
	number = rand() % 50;
	cout << number << endl; // ��ʾ����� 
	cout << "Please guess a number." << endl;
	int i = 1; 
	while (i <= 5) {
		if (win)
			break;
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
	return 0;	
} 
