#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 0x3f3f3f3f
const ll MAXN = 200 + 7;
const ll MAXM = 1e3 + 7;
const ll MOD = 1e9 + 7;
const double pi = acos(-1);
int cnt = -1, head[MAXM], dis[MAXN], cur[MAXM];
int n, m;
struct edge
{
    int to, value, net;
} e[MAXM << 1];
void add(int from, int to, int value)
{
    cnt++;
    e[cnt].to = to;
    e[cnt].value = value;
    e[cnt].net = head[from];
    head[from] = cnt;
}
int bfs(int st, int ed)
{ 
    queue<int> que;
    memset(dis, -1, sizeof(dis));
    dis[st] = 0;
    que.push(st);
    while (!que.empty())
    {
        int x = que.front();
        que.pop();
        for (int i = head[x]; i > -1; i = e[i].net)
        {
            int now = e[i].to;
            if (dis[now] == -1 && e[i].value)
            {
                que.push(now);
                dis[now] = dis[x] + 1;
            }
        }
    }
    return dis[ed] != -1;
}
int dfs(int x, int t, int maxflow)
{
    if (x == t)
        return maxflow;
    int ans = 0;
    for (int i = cur[x]; i > -1; i = e[i].net)
    { ///?????
        int now = e[i].to;
        if (dis[now] != dis[x] + 1 || e[i].value == 0 || ans >= maxflow)
            continue;
        cur[x] = i;
        int f = dfs(now, t, min(e[i].value, maxflow - ans));
        e[i].value -= f;
        e[i ^ 1].value += f;
        ans += f;
    }
    if (!ans)
        dis[x] = -1;
    return ans;
}
int Dinic(int st, int ed)
{
    int ans = 0;
    while (bfs(st, ed))
    {
        memcpy(cur, head, sizeof(head));
        int k;
        while ((k = dfs(st, ed, INF)))
            ans += k;
    }
    return ans;
}
void init()
{
    cnt=-1;
    memset(head,-1,sizeof(head));
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        init();
        scanf("%d%d", &n, &m);
        while (m--)
        {
            int u, v, t;
            scanf("%d%d%d", &u, &v, &t);
            add(u, v, t);
            add(v, u, 0);
        }
        printf("Case %d: %d\n", i, Dinic(1, n));
    }
    return 0;
}
