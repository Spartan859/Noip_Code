#include<iostream>
using namespace std;
int i,j,k,n,x,b[101];
int main() {
	cin>>n;
	for(i=0;i<=100;i++) b[i]=0;
	for(i=1;i<=n;i++) {
		cin>>x;
		b[x]=___(1)___;
	}
	___(2)____; 
	for(i=0;i<=100;i++)
		while(____(3)____) {
			cout<<____(4)______;
			k=k+1;
			b[i]=b[i]-1;
			if(____(5)______)
				cout<<endl;
		}
	cout<<endl;
	return 0;
} 

/*
输入n个0到100之间的整数，由小到大排序输出，
每个数字以空格分隔，每行打印8个数字。 
*/
