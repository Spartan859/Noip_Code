#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 1e5+7;
const LL inf = 1e10;
int n,m,k;
struct node
{
    int v,w;
    node(int v,int w)
    {
        this->v = v;
        this->w = w;
    }
};
vector<node>head[MAXN];
deque<int>q;
LL dis[MAXN];
bool vis[MAXN];

int key[MAXN];
vector<int>G0,G1;//存放0集合

int cnt;
LL sum;
void spfa()
{
    while(!q.empty())
    {
        int u = q.front();
        q.pop_front();
        if(dis[u]*cnt > sum)
        {
            q.push_back(u);
            continue;
        }
        vis[u] = 0;
        cnt--,sum -= dis[u];
        for(int i = 0,l = head[u].size(); i < l; ++i)
        {
            int v = head[u][i].v;
            int w = head[u][i].w;
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    cnt++,sum += dis[v];
                    if(q.empty() || dis[v] > dis[q.front()])q.push_back(v);
                    else q.push_front(v);
                }
            }
        }
    }
}


int main()
{
	#ifdef ONLINE_JUDGE
	freopen("strygwyr.in","r",stdin);
	freopen("strygwyr.out","w",stdout);
	#endif
    int t;
    scanf("%d",&t);
    int ca = 0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        scanf("%d",&k);
        for(int i = 1; i <= n; ++i)head[i].clear();
        int u,v,w;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            head[u].push_back(node(v,w));
        }
        
        for(int i = 0; i < k; ++i)
        {
            scanf("%d",&key[i]);
        }
        //枚举位置
        LL ans = 1e10;
        for(int bit = 0; bit < 17; ++bit)
        {
            G0.clear();
            G1.clear();
            for(int i = 0; i < k; ++i)
            {
                if(key[i] &(1<<bit))G0.push_back(key[i]);
                else G1.push_back(key[i]);
            }

            for(int i = 1; i <= n; ++i)dis[i] = inf;
            cnt = 0,sum = 0;
            for(int i = 0,l = G0.size(); i < l; ++i)
            {
                cnt++;
                q.push_back(G0[i]);
                dis[G0[i]] = 0;
                vis[G0[i]] = 1;
            }
            spfa();
            for(int i = 0,l = G1.size(); i < l; ++i)ans = min(ans,dis[G1[i]]);

            for(int i = 1; i <= n; ++i)dis[i] = inf;
            cnt = 0,sum = 0;
            for(int i = 0,l = G1.size(); i < l; ++i)
            {
                cnt++;
                q.push_back(G1[i]);
                dis[G1[i]] = 0;
                vis[G1[i]] = 1;
            }
            spfa();
            for(int i = 0,l = G0.size(); i < l; ++i)ans = min(ans,dis[G0[i]]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
