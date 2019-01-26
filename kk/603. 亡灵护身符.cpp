#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct zh{ll s,d;} x[10005];
bool cmp(const zh&a,const zh&b){return a.d>b.d;}
ll p,n,L,cnt,f[10005];
int main(){
  //freopen
	scanf("%lld",&n)
	for(ll i=1;i<=n;i++) scanf("%lld %lld",&x[i].s,&x[i].d);
	scanf("%lld %lld",&p,&L);
	x[0].d=p;
	sort(x,x+n+1,cmp);
	for(ll i=0;i<=n+1;i++){
		for(ll j=i;j>0;j--)
		    f[j]=max(f[j],f[j-1]+x[i].s)-x[i-1].d+x[i].d;
		if(f[i]<0){cout<<-1;return 0;}
		f[0]=L-p+x[i].d;
    }
	for(cnt=0;cnt<=n;cnt++)
		if(f[cnt]>=0)break;
	cout<<cnt<<endl;
	return 0;
}
