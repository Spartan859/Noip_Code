//STATUS:C++_AC_16MS_588KB
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=300,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

struct Edge{
    int u,v;
}e[N];

int first[N],nxt[N],vis[N],f[N][N],cost[N],cnt[N];
int n,m,mt;

void adde(int u,int v){
    e[mt].u=u,e[mt].v=v;
    nxt[mt]=first[u],first[u]=mt++;
}

void dfs(int u)
{
    int i,j,v,k;
    f[u][0]=0;
    i=first[u];
    if(i==-1){
        f[u][1]=cost[u];
        cnt[u]=1;
        return;
    }
    for(;i!=-1;i=nxt[i]){
        dfs(e[i].v);
        cnt[u]+=cnt[e[i].v];
        for(v=cnt[u];v>=0;v--){
            for(j=0;j<=v;j++){
                f[u][v]=Min(f[u][v],f[u][v-j]+f[e[i].v][j]);
            }
        }
    }
    f[u][++cnt[u]]=cost[u];
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,k,kt,ans,id,idfa;
    char s[110],cs[N*110];
    map<string,int> q;
    while(gets(s))
    {
        if(s[0]=='#')break;
        q.clear();
        mem(first,-1);
        mem(f,INF);
        mem(vis,0);mem(cnt,0);
        mt=0;
        ans=INF;
        sscanf(s,"%d%d",&n,&m);
        for(i=1,id=0;i<=n;i++){
            scanf("%s%d",s,&a);
            if(!q[s])q[s]=++id;
            idfa=q[s];
            cost[idfa]=a;
            gets(cs);
            if(!cs[0])continue;
            for(k=1,j=0;1;k++,j++){
                if(cs[k]==' ' || cs[k]=='\0'){
                    s[j]='\0';
                    if(!q[s])q[s]=++id;
                    kt=q[s];
                    vis[kt]=1;
                    adde(idfa,kt);
                    j=-1;
                    if(cs[k]=='\0')break;
                }
                else s[j]=cs[k];
            }
        }
        for(i=1;i<=n;i++){
            if(vis[i])continue;
            adde(0,i);
        }

        dfs(0);
        for(i=m;i<=n;i++)
            if(f[0][i]<ans)ans=f[0][i];

        printf("%d\n",ans);
    }
    return 0;
}
