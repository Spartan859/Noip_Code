#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
ll segt[N],a[100005],n,m,ans[100005];
void build_tree(ll root,ll st,ll ed){
	if(st==ed){segt[root]=a[st];return;} 
	ll mid=st+(ed-st)/2;
	build_tree(root*2+1,st,mid);
	build_tree(root*2+2,mid+1,ed);
	segt[root]=max(segt[root*2+1],segt[root*2+2]);
}
ll query_tree(ll root,ll nst,ll ned,ll qst,ll qed){
	if(qst>ned||qed<nst) return 0;
	if(qst<=nst&&qed>=ned) return segt[root];
	ll mid=nst+(ned-nst)/2;
	return max(query_tree(root*2+1,nst,mid,qst,qed),query_tree(root*2+2,mid+1,ned,qst,qed));
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	build_tree(0,1,n);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&l,&r);
		ans[i]=query_tree(0,1,n,l,r);
	}
	for(ll i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}
