#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 3e5 + 5;
const int Mo = 1e9 + 7;

int ans, n, all, inv[11], size[MAXN];
int f[MAXN][4][2][2], t[4][2][2];
int tot, Last[MAXN], Next[MAXN * 2], Go[MAXN * 2];

void link(int u, int v) {
	Next[++ tot] = Last[u], Last[u] = tot, Go[tot] = v; 
}

int C(int n, int m) {
	int ans = 1;
	for (int i = 0; i < m; i ++) ans = 1ll * ans * (n - i) % Mo;
	return 1ll * ans * inv[m] % Mo;
}

int pow(int x, int y) {
	int ans = 1;
	for (; y; y >>= 1, x = 1ll * x * x % Mo)
		if (y & 1) ans = 1ll * ans * x % Mo;
	return ans;
}

void dfs(int now, int pre) {
	f[now][0][0][0] = 1;
	f[now][0][1][0] = 1;
	for (int p = Last[now]; p; p = Next[p]) {
		int v = Go[p];
		if (v == pre) continue;
		dfs(v, now);
		memset(t, 0, sizeof t);
		for (int j1 = 3; j1 + 1; j1 --)
			for (int k1 = 0; k1 < 2; k1 ++)
				for (int l1 = 0; l1 < 2; l1 ++) {
					if (!f[now][j1][k1][l1]) continue;
					for (int j2 = 0; j2 < 4 - j1; j2 ++)
						for (int k2 = 0; k2 < 2; k2 ++)
							for (int l2 = 0; l2 < 2; l2 ++) {
								if (!f[v][j2][k2][l2] || (k2 == 1 && l1)) continue;
								int j3 = j1 + j2, k3 = k1 | k2, l3 = l1;
								if (k1 == 1 && k2 == 1) j3 ++, k3 = 0, l3 = 1;
								if (j3 < 4) (t[j3][k3][l3] += 1ll * f[now][j1][k1][l1] * f[v][j2][k2][l2] % Mo) %= Mo; 
							}
				}
		memcpy(f[now], t, sizeof t);
	}
}

void dfs2(int now, int pre) {
	size[now] = 1; int all = 0;
	for (int p = Last[now]; p; p = Next[p]) {
		int v = Go[p];
		if (v == pre) continue;
		dfs2(v, now);
		all = (all + 1ll * size[v] * size[now] % Mo) % Mo;
		size[now] += size[v];
	}
	for (int i = 0; i < 3; i ++)
		ans = (ans + 1ll * C(1ll * size[now] * (n - size[now]) % Mo, i) * C(all, 3 - i) % Mo) % Mo;
}

int main() {
	inv[0] = 1;
	for (int i = 1; i <= 10; i ++) inv[i] = 1ll * inv[i - 1] * pow(i, Mo - 2) % Mo;
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		link(u, v), link(v, u);
	}
	dfs(1, 0);
	ans = (f[1][3][0][0] + f[1][3][0][1]) % Mo;
	dfs2(1, 0);
	printf("%d\n", ans);
}
