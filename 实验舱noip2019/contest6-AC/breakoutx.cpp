#include"bits/stdc++.h"
#define F(i,j,n) for(register int i=j;i<=n;i++)
#define D(i,j,n) for(register int i=j;i>=n;i--)
#define ll long long
using namespace std;
namespace io{
	const int L=(1<<19)+1;
	char ibuf[L],*iS,*iT,c;int f;
	char gc(){
		if(iS==iT){
			iT=(iS=ibuf)+fread(ibuf,1,L,stdin);
			return iS==iT?EOF:*iS++;
		}
		return*iS++;
	}
	template<class I>void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
};
using io::gi;
using io::gc;
int t,n,m,f[1010],g[1010],l=1000,a[500010],b[500010];
int o(int x,int y){return (x-1)*m+y;}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("breakout.in","r",stdin);
	freopen("breakout.out","w",stdout);
	#endif
	gi(t);
	while(t--){
		gi(n);gi(m);
		F(i,0,l)f[i]=i;
//		F(i,0,10)printf("%d ",f[i]);puts("");
		F(i,1,n)F(j,1,m)gi(a[o(i,j)]);
		F(i,1,n)F(j,1,m)gi(b[o(i,j)]);
		F(j,1,n){
			F(i,0,l)g[i]=1<<25;
			F(i,1,m)g[b[o(j,i)]]=min(g[b[o(j,i)]],f[a[o(j,i)]]);
//			F(i,0,10)printf("%d ",g[i]);puts("");
			D(i,l,1)g[i-1]=min(g[i],g[i-1]);
			F(i,1,l)g[i]=min(g[i],g[i-1]+1);
			F(i,0,l)f[i]=g[i];
//			F(i,0,100)printf("%d ",f[i]);puts("");
		}
		printf("%d\n",f[0]);
	}
	return 0;
}

