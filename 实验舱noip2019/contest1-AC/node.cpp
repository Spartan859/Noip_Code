#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n,val[N];
ll son[N][2];
//ll fa[N];
ll stk[N],tp;
ll left_ans[N],right_ans[N];
void dfs(ll x){
	stk[++tp]=x;//»Î’ª
	if(val[x]<tp){
		ll fs=stk[tp-val[x]+1],fn=stk[tp-val[x]];
		if(son[fn][0]==fs) left_ans[fn]++;
		else right_ans[fn]++; 
	}
	if(son[x][0]) dfs(son[x][0]);
	if(son[x][1]) dfs(son[x][1]);
	tp--;
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",val+i);
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld",&son[i][0],&son[i][1]);
	dfs(1);
	for(ll i=1;i<=n;i++) printf("%lld %lld\n",left_ans[i],right_ans[i]);
	return 0;
}
