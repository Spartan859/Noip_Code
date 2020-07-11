#include<iostream>
#define N 1005
using namespace std;
long long ans,n,i,j,f[N];
int main(){
	cin>>n;
	f[1]=1;
	for(i=2;i+i<=n;i+=2){
		f[i]=1;
		for(j=1;j+j<=i;j++) f[i]+=f[j];
		f[i+1]=f[i];
	}
	ans=1;
	for(j=1;j*2<=n;j++) ans+=f[j];
	cout<<ans<<endl;
	return 0;
}

// f[n] = 1+ f[n/2]+f[n/2-1]+f[n/2-2]+f[n/2-3]+..+f[1]
/*
	f[1]=1;
	f[2]=2;
	f[3]=2;
	f[4]=4;   f[4]=1+f[2]+f[1]=4
	f[5]=4;   f[5]=1+f[2]+f[1]=4
	f[6]=6;   f[6]=1+f[3]+f[2]+f[1]=6
	f[7]=6;   f[7]=1+f[3]+f[2]+f[1]=6
	f[8]=10;  f[8]=1+f[4]+f[3]+f[2]+f[1]=10
	f[9]=10;
	f[10]=14;
	f[11]=14;
	f[12]=20;
*/
