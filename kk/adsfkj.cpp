#include<bits/stdc++.h>
using namespace std;
const int N = 210;
int f[N][N*N];
struct node{
    int a, b;
    bool operator <(node z) const{
        return b>z.b;
    }
}s[N];
int sum[N];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &s[i].a, &s[i].b);
    sort(s+1, s+1+n);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + s[i].a;
    memset(f, 127, sizeof(f));
    f[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= sum[i]; j++)
        {
            if(j>=s[i].a) f[i][j] = min(f[i][j], max(f[i-1][j-s[i].a], j+s[i].b));
            f[i][j] = min(f[i][j], max(f[i-1][j], sum[i]-j+s[i].b));
        }
    }
    int ans = 2147483647;
    for(int i = 0; i <= sum[n]; i++)
        ans = min(ans, f[n][i]);
    printf("%d\n", ans);
    return 0;
}
