#include"bits/stdc++.h"
#define F(i,j,n) for(register int i=j;i<=n;i++)
#define D(i,j,n) for(register int i=j;i>=n;i--)
#define ll long long
#define P 1000000007
#define N 5000010
using namespace std;
namespace io{
	const int L=(1<<19)+1;
	char ibuf[L],*iS,*iT,c;int f;
	char gc(){return getchar();}
	template<class I>void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
};
using io::gi;
using io::gc;
inline void add(int &x,int y){x+=y;if(x>=P)x-=P;}
const int i2=500000004,i6=166666668;
int n;
vector<int>G[300010];
int f[300010][4][2];
int s[300010];
int ans;
void dfs(int x,int p)
{
	int g[4][3];
	for(int i=0;i<=3;i++)for(int j=0;j<=2;j++)g[i][j]=0;
	g[0][0]=1;
	s[x]=1;
	for(int i=0;i<(int)G[x].size();i++)
	{
		int y=G[x][i];
		if(y==p)continue;
		dfs(y,x);
		for(int j=3;j>=0;j--)
		{
			for(int k=2;k>=0;k--)
			{
				int t=g[j][k];
				g[j][k]=0;
				if(!t)continue;
				for(int l=0;j+l<=3;l++)
				{
					add(g[j+l][k],1LL*t*f[y][l][0]%P);
					if(k+1<=2)add(g[j+l][k+1],1LL*t*f[y][l][1]%P);
				}
			}
		}
		s[x]+=s[y];
	}
	for(int i=0;i<=3;i++)
	{
		f[x][i][0]=g[i][0];
		if(i)add(f[x][i][0],(g[i-1][1]+g[i-1][2])%P);
		f[x][i][1]=(g[i][0]+g[i][1])%P; 
	}
	int num=1LL*n*(n-1)%P*i2%P;
	for(int i=0;i<(int)G[x].size();i++)
	{
		int y=G[x][i];
		if(y==p)continue;
		add(num,P-1LL*s[y]*(s[y]-1)%P*i2%P); 
	}
	add(num,P-1LL*(n-s[x])*(n-s[x]-1)%P*i2%P);
	add(ans,1LL*num*(num-1)%P*(num-2)%P*i6%P);
	num=1LL*s[x]*(n-s[x])%P;
	add(ans,P-1LL*num*(num-1)%P*(num-2)%P*i6%P);
}
int main()
{
//	#ifndef ONLINE_JUDGE
//	freopen("zll.in","r",stdin);
//	freopen("zll.out","w",stdout);
//	#endif
	gi(n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		gi(a);gi(b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1,0);
	add(ans,f[1][3][0]);
	printf("%d",ans);
	return 0;
}
