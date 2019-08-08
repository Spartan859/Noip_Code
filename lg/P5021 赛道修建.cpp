#include<bits/stdc++.h>
#define ll long long
#define N 50005
#define INF 2e18
using namespace std;
ll n,m;
vector<ll> es[N],w[N];
bool jh=1,lian=1;
ll esum;
ll len[N];
ll esmax,esmax2;
ll ans_m1;
bool cmp(const ll &a,const ll &b){
	return a>b;
}
void solve_jh(){
	if(m==1){
		printf("%lld\n",esmax+esmax2);
		return;
	}
	ll jhx[N]={0};
	for(ll i=0;i<n-1;i++) jhx[i+1]=w[1][i];
	sort(jhx+1,jhx+n,cmp);//big to small
	ll ans=INF;
	for(ll i=1;i<=m;i++) ans=min(ans,jhx[i]+jhx[m+m-i+1]);
	printf("%lld\n",ans);
}
bool ok_lian(ll x){
	ll now_m=0,nowsum=0;
	for(ll i=1;i<=n-1;i++){
		nowsum+=len[i];
		if(nowsum>=x){
			now_m++;
			nowsum=0;
		}
		if(now_m==m) return 1;
	}
	return 0;
}
void solve_lian(){
	//cout<<1<<endl;
	if(m==1){
		printf("%lld\n",esum);
		return;
	}
	ll l=1,r=esum,mid,ans;
	while(l<r){
		mid=(l+r+1)/2;
		//cout<<mid<<endl;
		//cout<<l<<' '<<r<<endl; 
		if(ok_lian(mid)) ans=l=mid;
		else r=mid-1;
	}
	printf("%lld\n",ans);
}
ll dfs(ll x,ll fa){//solve the d of tree
	ll sum1=0,sum2=0;//biggest & second biggest
	for(ll i=0;i<es[x].size();i++){
		ll y=es[x][i],z=w[x][i];
		if(y==fa) continue;
		sum2=max(sum2,dfs(y,x)+z);
		if(sum2>sum1) swap(sum1,sum2);
	}
	ans_m1=max(ans_m1,sum1+sum2);
	return sum1;
}
void solve_m1(){
	dfs(1,0);
	printf("%lld\n",ans_m1);
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1,a,b,l;i<=n-1;i++){
		scanf("%lld%lld%lld",&a,&b,&l);
		es[a].push_back(b);w[a].push_back(l);
		es[b].push_back(a);w[b].push_back(l);
		if(jh&&a!=1) jh=0;
		if(lian&&b!=a+1) lian=0; 
		esum+=l;
		len[a]=l;
		if(l>esmax2){
			esmax2=l;
			if(esmax2>esmax) swap(esmax,esmax2); 
		}//jh
	}
	if(jh){
		solve_jh();
		return 0;
	} 
	else if(lian){
		solve_lian();
		return 0;
	} 
	else if(m==1){
		solve_m1();
		return 0;
	} 
	return 0;
}
