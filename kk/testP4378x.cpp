#include <cstdio>
#include <algorithm>
struct node {
    int in;
    int zhi;
} a[100000];
bool cmp (const node &a, const node &b) {
    return a.zhi < b.zhi /*|| (a.zhi == b.zhi && a.in < b.in)*/;
}
int max(int a, int b) {return a < b ? b : a;}
int main() {
	freopen("testdata.in","r",stdin);
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i].zhi), a[i].in = i;
    std::sort(a, a+n, cmp);
    for (int j = 0; j < n; j++)
        ans = max(ans, a[j].in-j);
    printf("%d\n", ans+1);
}
