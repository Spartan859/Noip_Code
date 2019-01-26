#include<bits/stdc++.h> 
using namespace std;
struct node
{
    long long next,to;
}    e[2000005];
struct node1
{
    long long x,y,z;
}    a[1005];
long long head[1005],cnt,vis[1005];
inline void insert(long long u,long long v)
{
    e[++cnt].next=head[u];
    head[u]=cnt;
    e[cnt].to=v;
}
inline void dfs(long long now)
{
    vis[now]=1;
    for(long long i=head[now];i;i=e[i].next)
    {
        if(vis[e[i].to])    continue;
        dfs(e[i].to);
    }
}
int main()
{
    long long t,S,T,n,m,k;
    scanf("%lld",&t);
    while(t--)
    {
        cnt=0;
        memset(vis,0,sizeof(vis));
        memset(head,0,sizeof(head));
        scanf("%lld%lld%lld",&n,&m,&k);
        S=n+1,T=n+2;
        for(long long i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
            if(a[i].z<=k)    
            {
                insert(S,i);
                insert(i,S);
            }
            if(a[i].z>=m-k)
            {
                insert(T,i);
                insert(i,T);
            }
        }
        for(long long i=1;i<=n;i++)
            for(long long j=i+1;j<=n;j++)
            {
                if((a[j].x-a[i].x)*(a[j].x-a[i].x)+(a[j].y-a[i].y)*(a[j].y-a[i].y)+(a[j].z-a[i].z)*(a[j].z-a[i].z)<=4*k*k)
                {
                    insert(i,j);
                    insert(j,i);
                }
            }
        dfs(S);
        if(vis[T])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    
    return 0;
}
