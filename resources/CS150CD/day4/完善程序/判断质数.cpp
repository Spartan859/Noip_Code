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
给出一个正整数，判断这个数是否是素数。
输入格式:
一个正整数n(1<=n<=10000)
输出格式:
如果n是质数，输出YES，否则输出NO
输入样例:
10
输出样例:
NO 
*/
