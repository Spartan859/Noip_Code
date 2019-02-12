#include<bits/stdc++.h>
#define N 305
#define ll long long
using namespace std;
ll n,W,wght,vl;
double ans;
struct bw{
	ll w,v;
}trs[N];
bool cmp(const bw &a,const bw &b){
	return a.v*b.w>a.w*b.v;
}
int main(){
	scanf("%lld %lld",&n,&W);
	for(ll i=1;i<=n;i++) scanf("%lld %lld",&trs[i].w,&trs[i].v);
	sort(trs+1,trs+n+1,cmp);
	for(ll i=1;i<=n;i++){
		wght+=trs[i].w;
		vl+=trs[i].v;
		if(wght>=W) break;
	}
	ans=(double)vl/wght*1.0;
	cout<<fixed<<setprecision(0)<<ans*1000<<endl;
	return 0;
} 
