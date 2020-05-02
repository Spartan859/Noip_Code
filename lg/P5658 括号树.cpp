#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define maxn 500005

using namespace std;

int n;
char c[maxn];
int head[maxn], nxt[maxn], to[maxn], cnt, fa[maxn];
ll lst[maxn], sum[maxn], ans;
int s[maxn], top;

void add_edge(int u, int v)
{
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

void dfs(int x)
{
    int tmp = 0;
    if(c[x] == ')')
    {
        if(top)
        {
            tmp = s[top];
            lst[x] = lst[fa[tmp]] + 1;
            -- top; 
        }
    }
    else if(c[x] == '(') s[++ top] = x; 
    sum[x] = sum[fa[x]] + lst[x]; 
    for(int i = head[x]; i; i = nxt[i])
        dfs(to[i]); 
    if(tmp != 0) s[++ top] = tmp; 
    else if(top) -- top; 
}

int main()
{
    scanf("%d", &n);
    scanf("%s", c + 1);
    for(int i = 2; i <= n; i ++)
    {
        int f;
        scanf("%d", &f);
        add_edge(f, i);
        fa[i] = f;
    }
    dfs(1);
    for(int i = 1; i <= n; i ++)
        ans ^= sum[i] * (ll)i;
    printf("%lld\n", ans);
    return 0;
}
