#include<bits/stdc++.h>
#define fi(s) freopen(s,"r",stdin);
#define fo(s) freopen(s,"w",stdout);
#define INF 2e18
#define N 3005
#define ll long long
using namespace std;

ll n,m;
ll a[N];
ll f[N][N];//前i个选了j个加入第1组，至少产生多大的不公平度
//f[i][j]=min{f[i-1][j]+a[i]*j-a[i]*(m-j),f[i-1][j-1]+a[i]*(i-j)-a[i]*(n-m-i+j)} 

int main(){
	#ifndef ONLINE_JUDGE
	fi("split3.in");
	fo("split3x.out");
	#endif
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++/*,cout<<endl*/)
		for(ll j=0;j<=i;j++){
			f[i][j]=INF;
			if(j) f[i][j]=min(f[i][j],f[i-1][j-1]+a[i]*(i-j)-a[i]*(n-m-i+j));
			if(j<i) f[i][j]=min(f[i][j],f[i-1][j]+a[i]*j-a[i]*(m-j));
			//cout<<f[i][j]<<' ';
		}
	printf("%lld\n",f[n][m]);
	return 0;	
} 
