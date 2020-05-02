#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005, maxm = 30005;
struct node {
    int l, r, w;
} a[maxn];
bool vis[maxm];
int n, m, ans;
bool cmp(node a1, node a2) { return a1.r == a2.r ? a1.l < a2.l : a1.r < a2.r; }
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        for (int j = a[i].l; j <= a[i].r; j++) a[i].w -= vis[j];
        if (a[i].w <= 0)
            continue;
        for (int j = a[i].r; a[i].w && j >= a[i].l; j--)
            if (!vis[j]) {
                vis[j] = 1;
                a[i].w--;
            }
    }
    for (int i = 1; i <= 30000; i++) ans += vis[i];
    printf("%d", ans);
    return 0;
}
