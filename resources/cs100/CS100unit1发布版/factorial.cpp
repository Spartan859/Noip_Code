#include<iostream>
using namespace std;
long long f(int x){//����x�� 
	//���� long long 
	long long ans=1;//����ansΪ���������ͣ���ʼ��Ϊ1 
	for(int i=2;i<=x;i++)//forѭ����� 
		ans*=i;
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}
