#include<bits/stdc++.h>
#define N 1000005
#define ll long long
#define mod 100000007
using namespace std;
ll segt[N],a[100005],n,m,ans[100005],t,x,y,z,mark[N],cnt=0;
void build_tree(ll root,ll st,ll ed){
	mark[root]=0;
	if(st==ed){segt[root]=a[st];return;} 
	ll mid=st+(ed-st)/2;
	build_tree(root*2+1,st,mid);
	build_tree(root*2+2,mid+1,ed);
	segt[root]=max(segt[root*2+1],segt[root*2+2]);
}
void pushDown(ll root){
    if(mark[root] != 0){
        mark[root*2+1] += mark[root];
        mark[root*2+2] += mark[root];
        segt[root*2+1] += mark[root];
        segt[root*2+2] += mark[root];
        segt[root*2+1]%=mod;
        segt[root*2+2]%=mod;
        mark[root] = 0;
    }
}
void update(ll root, ll nstart, ll nend, ll ustart, ll uend, ll addVal){
    if(ustart > nend || uend < nstart) return ;
    if(ustart <= nstart && uend >= nend){
        mark[root] += addVal;
        segt[root] += addVal;
        segt[root]%=mod;
        return ;
    }
    pushDown(root);
    ll mid = (nstart + nend) / 2;
    update(root*2+1, nstart, mid, ustart, uend, addVal);
    update(root*2+2, mid+1, nend, ustart, uend, addVal);
    segt[root] = max(segt[root*2+1], segt[root*2+2]);
    segt[root]%=mod;
}
ll query_tree(ll root,ll nst,ll ned,ll qst,ll qed){
	if(qst>ned||qed<nst) return 0;
	if(qst<=nst&&qed>=ned) return segt[root];
	pushDown(root);
	ll mid=nst+(ned-nst)/2;
	return max(query_tree(root*2+1,nst,mid,qst,qed),query_tree(root*2+2,mid+1,ned,qst,qed));
}
int main(){
	scanf("%lld %lld",&n,&m);
	build_tree(0,1,n);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld %lld",&t,&x,&y,&z);
		if(t==1) update(0,1,n,x,y,z);
		else ans[cnt++]=query_tree(0,1,n,x,x)%mod;
	}
	for(ll i=0;i<cnt;i++) printf("%lld\n",ans[i]);
	return 0;
}
