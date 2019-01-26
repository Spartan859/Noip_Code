#include<bits/stdc++.h> 
using namespace std;
int n,m,lin[100010],in[100010],total,f[100010];
queue<int>q;
struct cym{
    int to,next;
}e[400010];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y) continue;
        e[++total].to=y;
        e[total].next=lin[x];
        lin[x]=total;
        in[y]++;
    }
    for(int i=1;i<=n;i++)
    if(in[i]==0)
    {
        f[i]=1;
        q.push(i);
    }
    while(!q.empty())
    {
        int cnt=q.front();q.pop();
        for(int i=lin[cnt];i;i=e[i].next)
        {
            f[e[i].to]=max(f[e[i].to],f[cnt]+1);
            if(--in[e[i].to]==0)q.push(e[i].to);    
        }   
    }
    for(int i=1;i<=n;i++)printf("%d ",f[i]);
return 0;
}
