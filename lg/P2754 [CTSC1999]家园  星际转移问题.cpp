#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
#define F(i,j,k) for (int i=j;i<=k;++i)
#define D(i,j,k) for (int i=j;i>=k;--i)
#define inf 0x3f3f3f3f
#define maxn 500005
 
int n,m,k,p[25],flag=0,S=0,T=maxn-1,ans=0;
int sta[25][25],num[25];
int h[maxn],to[maxn],ne[maxn],fl[maxn],fr[maxn],en=0;
int hash[25][500],cnt=0,dis[maxn];
queue <int> q;
 
void add(int a,int b,int c)
{
	to[en]=b;fr[en]=a;ne[en]=h[a];fl[en]=c;h[a]=en++;
	to[en]=a;fr[en]=b;ne[en]=h[b];fl[en]=0;h[b]=en++;
}
 
bool tell()
{
	memset(dis,-1,sizeof dis);
	while (!q.empty()) q.pop();
	dis[S]=0;q.push(S);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=h[x];i>=0;i=ne[i])
		{
			if (fl[i]>0&&dis[to[i]]==-1)
			{
				dis[to[i]]=dis[x]+1;
				q.push(to[i]);
			}
		}
	}
	if (dis[T]==-1) return false;
	return true;
}
 
int zeng(int k,int now)
{
	if (k==T) return now;
	int r=0;
	for (int i=h[k];i>=0&&now>r;i=ne[i])
		if (dis[k]+1==dis[to[i]]&&fl[i]>0)
		{
			int t=zeng(to[i],min(now-r,fl[i]));
			fl[i]-=t;fl[i^1]+=t;r+=t;
		}
	if (!r) dis[k]=-1;
	return r;
}
 
int main()
{
	memset(h,-1,sizeof h);
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,m)
	{
		scanf("%d",&p[i]);
		scanf("%d",&num[i]);
		F(j,0,num[i]-1)
		{
			scanf("%d",&sta[i][j]);
			if (sta[i][j]==-1) sta[i][j]=n+1;
		}
	}
	F(i,0,n+1)
		F(j,0,205)
			hash[i][j]=++cnt;
	add(S,hash[0][0],k);
	add(hash[n+1][0],T,inf);
	for (int z=0;z<=200;++z)
	{
		int tmp;
		F(i,0,n+1)
			add(hash[i][z],hash[i][z+1],inf);
		F(i,1,m)
			add(hash[sta[i][z%num[i]]][z],hash[sta[i][(z+1)%num[i]]][z+1],p[i]);
		add(hash[n+1][z+1],T,inf);
		while (tell()) while (tmp=zeng(S,inf)) ans+=tmp;
		if (ans==k)
		{
			flag=1;
			printf("%d\n",z+1);
			break; 
		}
	}
	if (!flag) printf("%d\n",0);
}
