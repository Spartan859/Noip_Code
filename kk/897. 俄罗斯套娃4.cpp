#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
struct twodim{
	ll x,y;
}inp[N];
ll a[N],d[N],n,len=1;
bool cmp(const twodim &a,const twodim &b){
	return a.x<b.x||a.x==b.x&&a.y>b.y;
}
int main(){
	freopen("russiandolls4.in","r",stdin);
	freopen("russiandolls4.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&inp[i].x);
    for(ll i=1;i<=n;i++) scanf("%lld",&inp[i].y);
    
    sort(inp+1,inp+n+1,cmp);
    for(ll i=1;i<=n;i++) a[i]=inp[i].y;
    d[1]=a[1];
    for(ll i=2;i<=n;i++){
        if(a[i]>d[len]) d[++len]=a[i];
        else{
            ll j=lower_bound(d+1,d+len+1,a[i])-d;
            d[j]=a[i]; 
        }
    }
    printf("%lld\n",len);
    return 0;
}
