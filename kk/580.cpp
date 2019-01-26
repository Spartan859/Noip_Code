#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,tme,ans;
struct rck{
	ll t,d;
}x[100005];
bool cmp(const rck &a,const rck &b){
	return a.t*b.d<b.t*a.d;
}
int main(){
	//freopen
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>x[i].t>>x[i].d;
	sort(x+1,x+n+1,cmp);
	for(ll i=1;i<=n;i++){
		ans+=tme*x[i].d;
		tme+=x[i].t*2;
	}
	cout<<ans<<endl;
	return 0;
}
