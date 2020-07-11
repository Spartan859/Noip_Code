#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=6e4;
int n,m,t,tot=0,atot=0,btot=0,ctot=0;
int d[N],query[N],f[N][20];
int ver[2*N],edge[2*N],Next[2*N],head[N];
bool ok,sta[N],need[N];
ll ans,tim[N],ned[N],dist[N][20];
pair<ll,int> h[N];
queue<int> q;
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}//1、输入
void bfs()
{
	q.push(1);
	d[1]=1;
	while(q.size())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=Next[i])
		{
			int y=ver[i];
			if(d[y])
				continue;
			d[y]=d[x]+1;
			f[y][0]=x,dist[y][0]=edge[i];
			for(int j=1;j<=t;j++)
			{
				f[y][j]=f[f[y][j-1]][j-1];
				dist[y][j]=dist[y][j-1]+dist[f[y][j-1]][j-1];
			}
			q.push(y);
		}
	}
}//2、树上倍增预处理
bool dfs(int x)
{
	bool pson=0;
	if(sta[x])
		return 1;
	for(int i=head[x];i;i=Next[i])
	{
		int y=ver[i];
		if(d[y]<d[x])
			continue;
		pson=1;
		if(!dfs(y))
			return 0;
	}
	if(!pson)
		return 0;
	return 1;
}//5、dfs寻找路径未被驻扎的叶子节点
bool check(ll lim)
{
	memset(sta,0,sizeof(sta));
	memset(tim,0,sizeof(tim));
	memset(ned,0,sizeof(ned));
	memset(h,0,sizeof(h));
	memset(need,0,sizeof(need));
	atot=0,btot=0,ctot=0;//初始化
	for(int i=1;i<=m;i++)
	{
		ll x=query[i],cnt=0;
		for(int j=t;j>=0;j--)
			if(f[x][j]>1 && cnt+dist[x][j]<=lim)
			{
				cnt+=dist[x][j];
				x=f[x][j];
			}
		if(f[x][0]==1 && cnt+dist[x][0]<=lim)
			h[++ctot]=make_pair(lim-cnt-dist[x][0],x);
		else
			sta[x]=1;
	}//4、上移军队并处理闲置军队
	for(int i=head[1];i;i=Next[i])
		if(!dfs(ver[i]))
			need[ver[i]]=1;//5、dfs寻找路径未被驻扎的叶子节点
	sort(h+1,h+ctot+1);
	for(int i=1;i<=ctot;i++)
		if(need[h[i].second] && h[i].first<dist[h[i].second][0])
			need[h[i].second]=0;
		else
			tim[++atot]=h[i].first;//6、对根节点的需要被驻扎的子节点进行初步处理
	for(int i=head[1];i;i=Next[i])
		if(need[ver[i]])
			ned[++btot]=dist[ver[i]][0];//7、找到仍需要被驻扎的节点并存储
	if(atot<btot)
		return 0;
	sort(tim+1,tim+atot+1),sort(ned+1,ned+btot+1);
	int i=1,j=1;
	while(i<=btot && j<=atot)
		if(tim[j]>=ned[i])
		{
			i++,j++;
		}
		else
			j++;
	if(i>btot)
		return 1;
	return 0;//8、利用贪心策略完成最后的匹配
}
int main()
{
	ll l=0,r=0,mid;
	cin>>n;
	t=log2(n)+1;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
		r+=z;
	}//1、输入
	bfs();//2、树上倍增预处理
	cin>>m;
	for(int i=1;i<=m;i++)
		scanf("%d",&query[i]);
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;
			ans=mid;
			ok=1;
		}
		else
			l=mid+1;//1、输入
	}//3、二分答案
	if(!ok)
		cout<<-1;
	else
		cout<<ans;//9、特判并输出
	return 0;
}
