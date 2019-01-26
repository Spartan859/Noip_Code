#include<bits/stdc++.h>
#define N 100005
#define H 20
#define ll long long
using namespace std;
ll a[N][H],lg[N]={0,0},n,m;
void st(){
	for (ll i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for(ll p=1;p<H;p++)
        for(ll i=1;i<=n-(1<<p)+1;i++)
            a[i][p]=max(a[i][p-1],a[i+(1<<(p-1))][p-1]);
}
ll query(ll l,ll r){
	ll p=lg[r-l+1];
	return max(a[l][p],a[r-(1<<p)+1][p]);
}
int main(){
    cin>>n>>m;
    for (ll i=1;i<=n;i++) cin>>a[i][0];
    st();
    for(ll i=1,l,r,mx,h;i<=m;i++){
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}
