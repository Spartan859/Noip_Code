#include<bits/stdc++.h>
#define N 70
using namespace std;
long long f[N];
int main(){
	int n;
	cin>>n;
	f[0]=f[1]=1;
	f[2]=2;
	for(int i=3;i<=n+n;i++) f[i]=f[i-1]+f[i-2];
	cout<<f[n+n]<<endl;
	return 0;
}
