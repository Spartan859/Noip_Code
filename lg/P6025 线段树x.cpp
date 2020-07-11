#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define Set(a) memset(a,0,sizeof(a))
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
typedef long long ll;
typedef unsigned long long ull;
template<typename T> inline T rd(T& x)
{
	T f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(T)(c-'0');
	x*=f;
	return x;
}
ll rd(){ll x;rd(x);return x;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int inf=1<<30;

#include<map>
#define int ll
ll n;
int _Logu(ll n)
{
	int l=0,r=63;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if((1ll<<mid)<n) l=mid+1;
		else r=mid;
	}
	return l;
}
bool ispow(ll n){return ((n&(n-1))==0);}
ll f(ll n,ll dep)
{
	if(ispow(n)||ispow(n-1)) return 2*n-1;
	return (f(n>>1,dep-1)+(1ll<<dep));
}
ll f(ll n){return f(n,_Logu(n));}
ll fx(ll n)
{
	if(n==0) return 0;
	ll ret=0;
	map<int,bool> m;
	#define add(x) if((x)<=n&&!m[x]) {m[x]=true;ret^=f(x);}
	for(re ll i=1;i<=n;i<<=1) {add(i) add(i+1)}
	if((n&1)==0&&!m[n]) ret^=f(n);
	return ret;
}
signed main()
{
	ll l,r;
	cin>>l>>r;
	cout<<(fx(r)^fx(l-1))<<endl;
	return 0;
}
