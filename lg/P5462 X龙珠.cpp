#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n,cnt;
struct xlz{
	ll ida,idb,numa,numb;
}tmp;
struct cmp{
	bool operator () (xlz a,xlz b){
		return a.numa>b.numa||a.numa==b.numa&&a.numb>b.numb;
	}
};
ll pre[N],nd[N],nxt[N],ans[N];
multiset<xlz,cmp> ms;
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&nd[i]);
		pre[i]=i-1;nxt[i]=i+1;
		if(i!=1) ms.insert((xlz){i-1,i,nd[i-1],nd[i]});
	} 
	while(!ms.empty()){
		tmp=*ms.begin();
		ms.erase(ms.begin());
		ans[++cnt]=tmp.numa;
		ans[++cnt]=tmp.numb;
		if(pre[tmp.ida]) 
			ms.erase(ms.find((xlz){pre[tmp.ida],tmp.ida,nd[pre[tmp.ida]],nd[tmp.ida]}));
		if(nxt[tmp.idb]!=n+1) 
			ms.erase(ms.find((xlz){tmp.idb,nxt[tmp.idb],nd[tmp.idb],nd[nxt[tmp.idb]]}));
		nxt[pre[tmp.ida]]=nxt[tmp.idb];
		pre[nxt[tmp.idb]]=pre[tmp.ida];
		if(pre[tmp.ida]&&nxt[tmp.idb]!=n+1)
			ms.insert((xlz){pre[tmp.ida],nxt[tmp.idb],nd[pre[tmp.ida]],nd[nxt[tmp.idb]]});	
	}
	for(ll i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}
