#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"queue"
#include"algorithm"
#include"string.h"
#include"string"
#include"math.h"
#include"vector"
#include"stack"
#include"map"
#define eps 1e-4
#define inf 0x3f3f3f3f
#define M 1209
#define PI acos(-1.0)
using namespace std;
int cnt,vis[M],num[M],s[M],g[M][M];
void bfs(int n)
{
    int i,j,id;
    memset(vis,0,sizeof(vis));
    memset(num,0,sizeof(num));
    cnt=0;
    for(i=n;i>=1;i--)
    {
        id=1;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&num[id]<num[j])
            {
                id=j;
            }
        }
        s[i]=id;
        vis[id]=1;
        for(j=1;j<=n;j++)
        {
            if(id!=j&&g[id][j]&&!vis[j])
                num[j]++;
        }
    }
}
int psq(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        int id;
        for(j=i+1;j<=n;j++)
        {
            if(g[s[i]][s[j]])
            {
                id=j;
                break;
            }
        }
        for(j=i+1;j<=n;j++)
        {
            if(g[s[i]][s[j]]&&id!=j&&g[s[id]][s[j]]==0)
            return 0;
        }
    }
    return 1;
 
}
int main()
{
    int n,m,i;
    while(scanf("%d%d",&n,&m),m+n)
    {
        memset(g,0,sizeof(g));
        for(i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b]=g[b][a]=1;
        }
        bfs(n);
        if(psq(n))
        {
            printf("Perfect\n\n");
        }
        else
            printf("Imperfect\n\n");
    }
    return 0;
}
