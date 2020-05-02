#include<bits/stdc++.h>
using namespace std;

struct psx{ int t, v; } a[200010];
priority_queue<int> q;
bool mycmp(psx a,psx b){ return a.t > b.t; }
int n, N, ans, y;

int main() {
	scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d",&a[i].t,&a[i].v),
		N = max(a[i].t, N);
    sort(a+1, a+1+n, mycmp);
	for(int i = N; i; i--) {
        while(a[++y].t >= i) q.push(a[y].v); y--;
        if(!q.empty()) ans += q.top(), q.pop();
    }
	printf("%d", ans);
	return 0;
}
