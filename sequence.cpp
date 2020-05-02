#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=100005;
ll n,m,T;
ll p[N];
struct acz{
	ll t,u,v;
}cz[N];
bool cmp(const acz &a,const acz &b){
	return a.t<b.t;
}
inline ll rpabs(ll x){
	return x>0?x:(-x);
}
namespace subtask1{
	void solve(){
		ll x,y,a,b;
		ll t,u,v;
		scanf("%lld%lld",&x,&y);
		scanf("%lld%lld",&a,&b);
		if(x>y) swap(x,y),swap(a,b);
		scanf("%lld%lld%lld",&t,&u,&v);
		if(t==1){
			if(y-x!=b-a) puts("NO");
			else puts("YES");
		}else{
			if(b-y!=x-a) puts("NO");
			else puts("YES");
		}
	}
}
namespace subtask2{
	void solve(){
		ll x,y,a,b;
		scanf("%lld%lld",&x,&y);
		scanf("%lld%lld",&a,&b);
		
		bool flag1=0,flag2=0;
		for(ll i=1;i<=m;i++){
			scanf("%lld%lld%lld",&cz[i].t,&cz[i].u,&cz[i].v);
			if(cz[i].t==1) flag1=1;
			if(cz[i].t==2) flag2=1;
		}
			
		if(!(flag1&&flag2)){
			if(flag1==1){
				if(y-x!=b-a) puts("NO");
				else puts("YES");
			}else if(flag2==1){
				if(b-y!=x-a) puts("NO");
				else puts("YES");
			}
		}else if(flag1&&flag2){
			if( (rpabs(y-x)&1)==(rpabs(b-a)&1) )
				puts("YES");
			else puts("NO");
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		if(n==2&&m==1){
			subtask1::solve();
			continue;
		}
		if(n==2){
			subtask2::solve();
			continue;
		}
	}
	return 0;
}
