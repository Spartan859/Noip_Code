#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
ll n,m; 
ll ans;
ll sum[N];
struct hv{
	ll h,v;
	bool operator < (const hv &a)const{
		return v>a.v;
	}
}a[N];
priority_queue<hv> q;ll hs,vs;//总高度，总价值 
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].h,&a[i].v);
		sum[i]=sum[i-1]+a[i].v;
	}
		
	for(ll i=1,ansx;i<=n;i++){//最远走到i的最大价值 
		q.push(a[i]);hs+=a[i].h-1;vs+=a[i].v*(a[i].h-1);
		while(1){
			hv x=q.top();
			if(hs-x.h<m-i){
				ansx=vs-x.v*max(0LL,hs-m+i-1)+sum[i];
				//cout<<ansx<<endl;
				ans=max(ans,ansx);
				break;
			}else{
				hs-=x.h-1;vs-=x.v*(x.h-1);
				q.pop();
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

