#include<iostream>
using namespace std;
int gcd(int x,int y){//���Լ�� 
	int tmp;
	while (tmp=x%y){//��=0ʱ��ֹͣѭ�� 
	//շת����� 
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



