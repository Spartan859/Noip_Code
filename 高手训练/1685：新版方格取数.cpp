#include<bits/stdc++.h> 
using namespace std;
	int n,m,ans;
	int mapx[17][17];
	bool b[17][17];
	int f[65536][17];
void edge(int now,int sum,int turn);
void dfs(int now,int x,int y,int sum,int turn) //x行y列，now取数情况，sum得分，turn取数个数
{
	int label=(x-1)*n+y;
	if (sum>f[now][label]||f[now][label]==0) f[now][label]=sum; else return; //注意后面||f[now][label]==0不可省略！因为有可能方格中有0使sum==0，但这时0仍然要取
	if (sum>ans) ans=sum;
	if (x+1<=m&&(now&(1<<x*n+y-1))==0) dfs(now+(1<<x*n+y-1),x+1,y,sum+mapx[x+1][y]*turn,turn+1); 
	if (y+1<=n&&(now&(1<<(x-1)*n+y))==0) dfs(now+(1<<(x-1)*n+y),x,y+1,sum+mapx[x][y+1]*turn,turn+1);
	if (x-1>=1&&(now&(1<<(x-2)*n+y-1))==0) dfs(now+(1<<(x-2)*n+y-1),x-1,y,sum+mapx[x-1][y]*turn,turn+1);
	if (y-1>=1&&(now&(1<<(x-1)*n+y-2))==0) dfs(now+(1<<(x-1)*n+y-2),x,y-1,sum+mapx[x][y-1]*turn,turn+1);
	if (x==1||y==1||x==m||y==n) edge(now,sum,turn);
}
void edge(int now,int sum,int turn) //取到边缘
{
	for (int i=1;i<=m;i++)
	{
		if ((now&(1<<(i-1)*n))==0) dfs(now+(1<<(i-1)*n),i,1,sum+mapx[i][1]*turn,turn+1);
		if ((now&(1<<i*n-1))==0) dfs(now+(1<<i*n-1),i,n,sum+mapx[i][n]*turn,turn+1);
	}
	for (int j=1;j<=n;j++)
	{
		if ((now&(1<<j-1))==0) dfs(now+(1<<j-1),1,j,sum+mapx[1][j]*turn,turn+1);
		if ((now&(1<<(m-1)*n+j-1))==0) dfs(now+(1<<(m-1)*n+j-1),m,j,sum+mapx[m][j]*turn,turn+1);
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&mapx[i][j]);
	if (m<=2||n<=2)
	{
		int x=0;
		int y=0;
		for (int i=1;i<=m*n;i++)
		{
			int min=2147483647;
			for (int j=1;j<=m;j++)
				for (int k=1;k<=n;k++)
					if (mapx[j][k]<min&&!b[j][k])
					{
						min=mapx[j][k];
						x=j;
						y=k;
					}
			b[x][y]=true;
			ans+=min*i;
		}
		printf("%d",ans);
	}
	else 
	{
		edge(0,0,1);
		printf("%d",ans);
	}
	return 0;
}
