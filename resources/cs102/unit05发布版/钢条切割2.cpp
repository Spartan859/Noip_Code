#include<iostream>
#define N 105
using namespace std;
int f[N],fd[N],p[N],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	f[0]=0;fd[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(f[i-j]+p[j]>f[i]){
				f[i]=f[i-j]+p[j];
				fd[i]=j;
			}
	cout<<f[n]<<endl;
	cout<<n<<"="<<fd[n];
	while(1){
		n-=fd[n];
		if(n==0)break;
		cout<<"+"<<fd[n];
	}
	cout<<endl;
	return 0;
}


