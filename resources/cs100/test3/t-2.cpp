#include<iostream>
#define M 10005
using namespace std;
int n,m,d[M],temp,temp1;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>d[i];
	for(int a=0;a<n-m+1;a++){
		for(int b=a;b<=a+m-1;b++) temp+=d[b];
		if(temp>=temp1) temp1=temp;
		temp=0;
	}
	cout<<temp1;
	return 0;
}
