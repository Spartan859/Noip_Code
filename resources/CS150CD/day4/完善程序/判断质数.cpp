#include<iostream>
using namespace std;
int main() {
	int ____(1)____;
	cin>>n;
	if(n==2) cout<<____(2)____;
	else if(____(3)____ || n%2==0)
		cout<<"NO";
	else {
		i=3;
		while(i*i<=n) {
			if(____(4)____) {
				cout<<"NO";
				return 0;
			}
			i=i+2;
		}
		cout<<"YES";
	}
	return 0;
}


/*
����һ�����������ж�������Ƿ���������
�����ʽ:
һ��������n(1<=n<=10000)
�����ʽ:
���n�����������YES���������NO
��������:
10
�������:
NO 
*/
