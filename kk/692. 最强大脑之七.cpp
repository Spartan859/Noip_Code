#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
ll c[N],x[N],y[N],sa[N];
string s;
ll n,m;
int main(){
    cin>>s;
    n=s.size();
    for(ll i=0;i<n;i++) x[i]=s[i],m=max(m,x[i]);
    for(ll i=0;i<n;i++) c[x[i]]++;
    for(ll i=2;i<=m;i++) c[i]+=c[i-1];
    for(ll i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(ll k=1;k<=n;k<<=1){
        ll num=0;
        for(ll i=n-k;i<n;i++) y[num++]=i;
        for(ll i=0;i<n;i++) if(sa[i]>=k)y[num++]=sa[i]-k;
        for(ll i=1;i<=m;i++) c[i]=0;
        for(ll i=0;i<=n;i++) c[x[i]]++;
        for(ll i=2;i<=m;i++) c[i]+=c[i-1];
        for(ll i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i],y[i]=0;
        swap(x,y);
        num=1;x[sa[0]]=1;
        for(ll i=1;i<n;i++)
            if(y[sa[i]]!=y[sa[i-1]]||y[sa[i]+k]!=y[sa[i-1]+k]) x[sa[i]]=++num;
            else x[sa[i]]=num;
        if(num>=n) break;
        m=num;
    }
	for(ll i=0;i<n;i++) cout<<sa[i]+1<<' ';
    return 0;
}
