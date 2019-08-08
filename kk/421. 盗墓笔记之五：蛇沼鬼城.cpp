#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,y,f[2][2][2];
const ll mod=100000007;
ll dt(ll x,ll t){
	return (x&(1<<(t-1)))>0;
}
int main(){
	scanf("%lld %lld %lld",&n,&x,&y);
	f[0][0][0]=1;
	for(ll i=1;i<=n;i++)
		for(ll u=0;u<=1;u++)
			for(ll v=0;v<=1;v++){
				f[i&1][u][v]=0;
				for(ll k=0;k<16;k++){
					ll u2=(k&8)>0,v2=(k&4)>0,a=(k&2)>0,b=k&1;
					if((u2+a+dt(x,i))/2!=u||(v2+b+dt(y,i))/2!=v) continue;
					if(a==0&&b==1) continue;
					if((u2+a+dt(x,i))%2==0&&(v2+b+dt(y,i))%2==1) continue;
					f[i&1][u][v]+=f[i&1^1][u2][v2]%=mod;
				}
			}
	printf("%lld\n",f[n&1][0][0]);
	return 0;
}
