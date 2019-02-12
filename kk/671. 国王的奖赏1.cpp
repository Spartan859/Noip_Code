#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll d[N][N],n,m,a[N],f[N];
int main(){
	freopen("reward1.in","r",stdin);
	freopen("reward1.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			scanf("%lld",&d[i][j]);
	for(ll j=1;j<=m;j++)
		for(ll i=1;i<=n;i++) a[j]+=d[i][j];
	for(ll i=1;i<=m;i++){
		f[i]=f[i-1]+a[i];
		if(f[i]<0) f[i]=0;
	}
	cout<<*max_element(f+1,f+m+1)<<endl;
	return 0;
}
