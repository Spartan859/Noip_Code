#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN=110000;
struct Edge
{
    int u, v;
    Edge() {}
    Edge(int a, int b): u(a), v(b) {}
} e[MAXN];
vector<int> g[MAXN], h[MAXN];
int a[MAXN];
int bel[MAXN], bw[MAXN];
ll sum[MAXN];
bool tag[MAXN];
void dfs1(int u, int c)
{
    bel[u]=c, sum[c]+=a[u];
    for (int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if (!bel[v]) dfs1(v, c);
    }
}
bool dfs2(int u, int c, bool& t, ll& sb, ll& sw)//cÂ·¾¶ÆæÅ¼ 
{
    if (~bw[u]) return bw[u]==c;
    bw[u]=c, t|=tag[u];
    if (c==0) sb+=sum[u];
    else sw+=sum[u];
    bool ret=1;
    for (int i=0; i<h[u].size(); i++)
    {
        int v=h[u][i];
        ret&=dfs2(v, c^1, t, sb, sw);
    }
    return ret;
}
int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, p=0, k=0;
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++) scanf("%d", &a[i]);
        for (int i=1; i<=n; i++)
        {
            int x; scanf("%d", &x); a[i]=x-a[i];
            g[i].clear(), h[i].clear();
        }
        for (int i=1; i<=m; i++)
        {
            int t, u, v;
            scanf("%d%d%d", &t, &u, &v);
            if (t==1) e[++p]=Edge(u, v);// 
            else g[u].push_back(v), g[v].push_back(u);
        }
        memset(bel, 0, sizeof bel);
        memset(sum, 0, sizeof sum);
        memset(tag, 0, sizeof tag);
        for (int i=1; i<=n; i++)
            if (!bel[i]) dfs1(i, ++k);
        for (int i=1; i<=p; i++)
            if (bel[e[i].u]==bel[e[i].v]) tag[bel[e[i].u]]=1;
            else
            {
                h[bel[e[i].u]].push_back(bel[e[i].v]);
                h[bel[e[i].v]].push_back(bel[e[i].u]);
            }
        memset(bw, -1, sizeof bw);
        bool ans=1;
        for (int i=1; i<=k; i++)
            if (bw[i]==-1)
            {
                bool tg=0; ll sumb=0, sumw=0;
                if (dfs2(i, 0, tg, sumb, sumw))
                    if (tg) ans&=(sumb+sumw)%2==0;
                    else ans&=sumb==sumw;
                else ans&=(sumb+sumw)%2==0;
            }
        puts(ans?"YES":"NO");
    }
    return 0;
}
