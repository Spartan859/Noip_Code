#include<iostream>
#define M 100001
using namespace std;
int f[M],n,a,b,xa,xb,i,j;
int main(){
	cin>>n>>a>>b;
	f[0]=0;
	for(i=1;i<=n;i++){
		if(i>=a) xa=f[i-a]+a;
		else xa=0;
		if(i>=b) xb=f[i-b]+b;
		else xb=0;
		f[i]=max(xa,xb);
	}
	cout<<f[n]<<endl;	
	return 0;
}



