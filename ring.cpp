#include<bits/stdc++.h>
#define N 15
#define ll long long
using namespace std;
ll n,m;
ll a[N*2],k[N],ans[N];
int main(){
	//freopen("ring.in","r",stdin);
	//freopen("ring.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",a+i);
		ans[0]+=a[i]*a[i];
	} 
	for(ll i=1;i<=m;i++)
		scanf("%lld",k+i);
	do{
		for(ll i=1;i<=n;i++) a[n+i]=a[i];
		for(ll kx=1;kx<=m;kx++){
			if(k[kx]==0) continue;
			ll tmp=0;
			for(ll i=1;i<=n;i++) tmp+=a[i]*a[i+k[kx]];
			ans[k[kx]]=max(ans[k[kx]],tmp);
		}
	}while(next_permutation(a+1,a+n+1));
	for(ll i=1;i<=m;i++) printf("%lld\n",ans[k[i]]);
	return 0;
}
/*
10 10
1 2 3 4 5 6 7 8 9 10
0
1
2
3
4
5
6
7
8 
9
*/

