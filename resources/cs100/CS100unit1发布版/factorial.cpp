#include<iostream>
using namespace std;
long long f(int x){//返回x！ 
	//长长 long long 
	long long ans=1;//定义ans为长整数类型，初始化为1 
	for(int i=2;i<=x;i++)//for循环语句 
		ans*=i;
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}
