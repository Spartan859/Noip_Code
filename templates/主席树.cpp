#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
int a[maxn], b[maxn], n, m, q, p, sz;
int lc[maxn << 5], rc[maxn << 5], sum[maxn << 5], rt[maxn << 5];
//¿Õ¼äÒª×¢Òâ

inline int read(){
	int s = 0, w = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') w = -1;
	for (; isdigit(c); c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
	return s * w;
}

void build(int &rt, int l, int r){
	rt = ++sz, sum[rt] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lc[rt], l, mid); build(rc[rt], mid + 1, r);
}

int update(int o, int l, int r){
	int oo = ++sz;
	lc[oo] = lc[o], rc[oo] = rc[o], sum[oo] = sum[o] + 1;
	if (l == r) return oo;
	int mid = (l + r) >> 1;
	if (mid >= p) lc[oo] = update(lc[oo], l, mid); else rc[oo] = update(rc[oo], mid + 1, r);
	return oo;
}

int query(int u, int v, int l, int r, int k){
	int mid = (l + r) >> 1, x = sum[lc[v]] - sum[lc[u]];
	if (l == r) return l;
	if (x >= k) return query(lc[u], lc[v], l, mid, k); else return query(rc[u], rc[v], mid + 1, r, k - x);
}

int main(){
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	q = unique(b + 1, b + 1 + n) - b - 1;
	build(rt[0], 1, q);
	for (int i = 1; i <= n; ++i){
		p = lower_bound(b + 1, b + 1 + q, a[i]) - b;
		rt[i] = update(rt[i - 1], 1, q);
	} 
	while (m--){
		int l = read(), r = read(), k = read();
		printf("%d\n", b[query(rt[l - 1], rt[r], 1, q, k)]);
	}
	return 0;
}
