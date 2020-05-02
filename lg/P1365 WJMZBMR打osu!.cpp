#include<bits/stdc++.h>
#define N 300005
#define ll long long
using namespace std;
long double f[N],g[N];
string s;
ll n;
int main(){
	scanf("%lld",&n);
	cin>>s;
	for(ll i=1;i<=n;i++){
		if(s[i-1]=='o') g[i]=g[i-1]+1.0,f[i]=f[i-1]+2*g[i-1]+1.0;
		else if(s[i-1]=='x') g[i]=0,f[i]=f[i-1];
		else f[i]=f[i-1]+g[i-1]+0.5,g[i]=0.5*g[i-1]+0.5;
	}
	printf("%.4Lf\n",f[n]);
	return 0;
}

