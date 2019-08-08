#include<bits/stdc++.h>
#define N 100005
#define INF 2e9
#define ll long long
using namespace std;
ll a[N],n,cur=1,hd,minn,ans;
int main(){
	freopen("pirate.in","r",stdin);
	freopen("pirate.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	while(1){
		hd=cur;minn=INF;
		for(ll i=hd;i<=(hd==1?n-1:n);) 
			if(a[i]>0) minn=min(minn,a[i]),i+=2;
			else i++;
		ans+=minn;
		cur=INF;
		for(ll i=hd;i<=(hd==1?n-1:n);) 
			if(a[i]>0){
				a[i]-=minn;
				i+=2;
			}
			else i++;
		for(ll i=1;i<=n;i++) if(a[i]>0){
			cur=i;
			break;
		} 
		if(cur==INF) break;
	}
	printf("%lld",ans);
	return 0;
}
