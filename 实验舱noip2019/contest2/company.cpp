#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,m,q;
struct ljcmd{
	ll tp,x,y;
}cmds[N];
ll son[N][2];
ll qs[N];

inline void excthhh(ll tp,ll x,ll y){
	if(tp==0) return;
	if(tp==1) qs[x]+=y;
	if(tp==2) for(ll i=1;i<=q;i++) if(qs[i]) qs[i]*=x;
}
void dfs(ll x){//从x节点开始，将所有下属指令全部执行 
	if(x<=n){
		excthhh(cmds[x].tp,cmds[x].x,cmds[x].y);
		return;
	} 
	ll lft=son[x][0],rt=son[x][1];
	//cout<<lft<<' '<<rt<<endl;
	if(lft<=n) excthhh(cmds[lft].tp,cmds[lft].x,cmds[lft].y);
	else dfs(lft);
	if(rt<=n) excthhh(cmds[rt].tp,cmds[rt].x,cmds[rt].y);
	else dfs(rt);
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1,t,a,b;i<=n;i++){
		scanf("%lld",&t);
		if(t==1) scanf("%lld%lld",&a,&b);
		else{
			scanf("%lld",&a);
			b=0;
		} 
		cmds[i]=(ljcmd){t,a,b};
	}
	for(ll i=1,a,b;i<=n-1;i++){
		scanf("%lld%lld",&a,&b);
		son[i+n][0]=a;
		son[i+n][1]=b;
	}
	for(ll i=1,c;i<=m;i++){
		scanf("%lld",&c);
		dfs(c);
	}
	for(ll i=1;i<=q;i++) printf("%lld\n",qs[i]);
	return 0;
}
