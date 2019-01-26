#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005][35],lg[100005]={0,0},n,m,H=20;
int main(){
    cin>>n>>m;
    for (ll i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    for (ll i=1;i<=n;i++) cin>>a[i][0];
    for (ll h=1;h<H;h++)
        for (ll i=1;i<=n-(1<<h)+1;i++)
            a[i][h]=max(a[i][h-1],a[i+(1<<(h-1))][h-1]);
    
    for(ll i=1,l,r,mx,h;i<=m;i++){
        cin>>l>>r;
        h=lg[r-l+1];
        mx=max(a[l][h],a[r-(1<<h)+1][h]);
        cout<<mx<<endl;
    }
    return 0;
}
