#include<bits/stdc++.h>
#define M 200005
#define ll long long
using namespace std;
struct twodim{
	ll x,y;
}inp[M];
ll a[M],d[M],n,m,len=1;
bool cmp(const twodim &a,const twodim &b){
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
int main(){
	freopen("river.in","r",stdin);
	freopen("river.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++) scanf("%lld %lld",&inp[i].x,&inp[i].y);
    sort(inp+1,inp+m+1,cmp);
    for(ll i=1;i<=m;i++) a[i]=inp[i].y;
    d[1]=a[1];
    for(ll i=2;i<=m;i++){
        if(a[i]>=d[len]) d[++len]=a[i];
        else{
            ll j=upper_bound(d+1,d+len+1,a[i])-d;
            d[j]=a[i]; 
        }
    }
    printf("%lld\n",m-len);
    return 0;
}
