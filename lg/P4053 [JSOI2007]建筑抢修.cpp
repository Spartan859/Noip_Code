#include<bits/stdc++.h> 
#define MAXN 200200
using namespace std;

int n;
int T;
int ans;
struct node
{
    int w;
    int t;
}a[MAXN];
priority_queue<int> Q;

bool cmp (node x, node y)
{
    return x.t < y.t;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].w, &a[i].t);
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        if(T + a[i].w > a[i].t)
        {
            if(a[i].w < Q.top())
            {
                T -= Q.top();
                Q.pop();
                Q.push(a[i].w);
                T += a[i].w;
            }
        }
        else 
        {
            Q.push(a[i].w);
            ans++;
            T += a[i].w;
        }
    }
    printf("%d\n", ans);
    return 0;
}
