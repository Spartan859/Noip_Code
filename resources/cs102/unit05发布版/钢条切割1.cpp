#include<iostream>
#define N 105
using namespace std;
int f[N],p[N],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i]=max(f[i-j]+p[j],f[i]);
	cout<<f[n]<<endl;
	return 0;
}


