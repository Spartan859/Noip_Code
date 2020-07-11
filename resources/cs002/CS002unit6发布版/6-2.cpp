#include<iostream>
using namespace std;
int n;
int main(){
	cin>>n;
	int a[20];
	int i;
	a[0]=0;
	a[1]=1;
	for(i=2;i<=n;i++) a[i]=a[i-2]+a[i-1];
	for(i=n;i>=0;i--) cout<<a[i]<<' ';
	return 0;
}
