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
	cout << "Please guess a number." << endl;
	// �²�1 
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
	// �²�2 
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
	// �²�3 
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
	// �²�4 
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
	// �²�5 
	if (!win) {
		cin >> n;
		if (n > number)  // ����µ����ִ��� 
			cout << "Your guess is bigger than the number,you lose." << endl;
		else if (n < number) // ����µ�����С��
			cout << "Your guess is smaller than the number,you lose." << endl;
		else {  // �ɹ��¶����� 
			cout << "You win. The number is " << number << endl;
			win = true;
		}
	}
	return 0;	
} 
