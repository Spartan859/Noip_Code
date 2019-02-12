#include<bits/stdc++.h>
#define ll long long
#define N 200000
#define T 100
#define S 100000
#define Y 200
using namespace std;
ll n,bit[T+5][Y+5],fnans[N+5];
ll tmp1,tmp2;
struct xs{ll t,s,y,id;}p[N+5];
bool cmp(const xs &a,const xs &b){return a.s>b.s||a.s==b.s&&a.t>b.t;}

void update(ll x,ll y,ll a){
	for(ll i=x;i<=T;i+=(i&(-i)))
		for(ll j=y;j<=Y;j+=(j&(-j)))
			bit[i][j]+=a;
}

ll query(ll x,ll y){
	ll sum=0;
	for(ll i=x;i;i-=(i&(-i)))
		for(ll j=y;j;j-=(j&(-j)))
			sum+=bit[i][j];
	return sum;
}
int main(){
	freopen("zhazha.in","r",stdin);
	freopen("zhazha.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){scanf("%lld",&p[i].t);p[i].t++;p[i].id=i;}
	for(ll i=1;i<=n;i++) scanf("%lld",&p[i].s); 
	for(ll i=1;i<=n;i++) scanf("%lld",&p[i].y);
	sort(p+1,p+n+1,cmp);
	for(ll i=1;i<=n;i++){
		update(p[i].t,p[i].y,1);
		fnans[p[i].id]=query(p[i].t-1,p[i].y-1);
	}
	for(ll i=1;i<=n;i++) printf("%lld ",fnans[i]);
	return 0;
}
