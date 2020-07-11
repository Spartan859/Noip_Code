#include <bits/stdc++.h>
#define For(i,a,b) for ( int i=(a);i<=(b);i++ )
#define Dow(i,b,a) for ( int i=(b);i>=(a);i-- )
#define GO(i,x) for ( int i=head[x];i;i=e[i].nex )
#define mem(x,s) memset(x,s,sizeof(x))
#define cpy(x,s) memcpy(x,s,sizeof(x))
#define YES return puts("YES"),0
#define NO return puts("NO"),0
#define GG return puts("-1"),0
#define pb push_back
using namespace std;

inline int read()	
{
	int sum=0,ff=1; char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(isdigit(ch))
		sum=sum*10+(ch^48),ch=getchar();
	return sum*ff;
}

const int mod=1e9+7;
const int mo=998244353;
const int N=5005;
const int M=1<<13|1;

int n,m,l,val[N],a[N][N],f[N][M],High[M];
vector<int> G[N];

int main()
{
	n=read();m=read();l=read();
	For(i,1,n) val[i]=read();
	For(i,1,m)
	{
		int x,y;
		x=read(),y=read();
		if(!a[x][y]) a[x][y]=1,G[x].pb(y);
	}
	For(S,0,(1<<l+1)-1) for ( int j=l+1;~j;j-- ) if((S>>j)&1)
	{
		High[S]=j;
		break;
	}
	memset(f,-1,sizeof(f));
	For(i,1,n)
	{
		if(f[i][1]==-1) f[i][1]=0;
		For(S,0,(1<<l+1)-1)
		{
			if(!(S&1)) continue;
			int idv=i+High[S];
			if(f[i][S]==-1) continue;
			For(j,0,(int)G[idv].size()-1)
			{
				int v=G[idv][j];
				if(a[i][v]) f[v][1]=max(f[i][S]+val[v],f[v][1]);
				if(v-i>l) continue;
				int nxt=S|(1<<v-i);
				f[i][nxt]=max(f[i][nxt],f[i][S]+val[v]);
			}
			For(j,0,(int)G[i].size()-1)
			{
				int v=G[i][j];
				if(v-idv>l) continue;//1:
				if(v>idv)
				{
					int nxt=(S>>idv-i)|(1<<v-idv);
					if(S>>v-i&1) f[idv][nxt]=max(f[idv][nxt],f[i][S]);
					else f[idv][nxt]=max(f[idv][nxt],f[i][S]+val[v]);
				}
				else 
				{
					int nxt=S>>v-i|1;
					if(S>>v-i&1) f[v][nxt]=max(f[v][nxt],f[i][S]);
					else f[v][nxt]=max(f[v][nxt],f[i][S]+val[v]);
				}
			}
		}
	}
	printf("%d\n",f[n][1]);
	return 0;
}
