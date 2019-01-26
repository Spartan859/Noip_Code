#include<bits/stdc++.h>
#define ll long long
#define INF 10005
using namespace std;
ll n,h[100005],ans;
void flrd(ll l,ll r){
	if(l==r){
		ans+=h[l];
		return;
	}
	ll tmp=INF,cur=l;
	for(ll i=l;i<=r;i++) tmp=min(tmp,h[i]);
	ans+=tmp;
	for(ll i=l;i<=r;i++){
		h[i]-=tmp;
		if(h[i]==0){
			if(cur!=i){
				flrd(cur,i-1);
				cur=i+1;
			}
			else cur++;
		}
	}
	if(h[r]!=0) flrd(cur,r);
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",h+i);
	flrd(1,n);
	cout<<ans<<endl;
	return 0;
}
