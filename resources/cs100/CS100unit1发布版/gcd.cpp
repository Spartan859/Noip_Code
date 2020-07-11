#include<iostream>
using namespace std;
int gcd(int x,int y){//最大公约数 
	int tmp;
	while (tmp=x%y){//当=0时，停止循环 
	//辗转相除法 
		x=y;
		y=tmp;
	}
	return y;
}	
int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}



