#include<bits/stdc++.h>
#define N 300005
#define ll long long
using namespace std;
long double f[N],g[N],tmp;
string s;
ll n;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%Lf",&tmp);
		//if(s[i-1]=='o') g[i]=g[i-1]+1.0,f[i]=f[i-1]+2*g[i-1]+1.0;
		//else if(s[i-1]=='x') g[i]=0,f[i]=f[i-1];
		
		f[i]=f[i-1]+(2*g[i-1]+1.0)*tmp,g[i]=tmp*(g[i-1]+1.0);
	}
	printf("%.15Lf\n",f[n]);
	return 0;
}

