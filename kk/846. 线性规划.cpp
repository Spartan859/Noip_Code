#include <bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n, m, num, top, cnt;
ll d[N], dfn[N], low[N], st[N], c[N], deg[N], f[N], scc[N];
bool ins[N];
vector<pair<ll, ll> > e[N], ec[N];
queue<ll> q;

inline void add(ll x, ll y, ll z) {
	e[x].push_back(make_pair(y, z));
}

inline void addc(ll x, ll y, ll z) {
	ec[x].push_back(make_pair(y, z));
	++deg[y];
}

void tarjan(ll x) {
	dfn[x] = low[x] = ++num;
	st[++top] = x;
	ins[x] = 1;
	for (ll i = 0; i < e[x].size(); i++) {
		ll y = e[x][i].first;
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
		} else if (ins[y])
			low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		++cnt;
		ll y;
		do {
			y = st[top--];
			ins[y] = 0;
			c[y] = cnt;
			++scc[cnt];
		} while (y != x);
	}
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= m; i++) {
		ll t, a, b;
		scanf("%lld %lld %lld", &t, &a, &b);
		if (t == 2) add(a, b, 1);
		else if (t == 3) add(b, a, 0);
		else if (t == 4) add(b, a, 1);
		else if (t == 5) add(a, b, 0);
		else {
			add(a, b, 0);
			add(b, a, 0);
		}
	}
	for (ll i = 1; i <= n; i++) add(0, i, 1);
	tarjan(0);
	for (ll x = 0; x <= n; x++)
		for (ll i = 0; i < e[x].size(); i++) {
			ll y = e[x][i].first, z = e[x][i].second;
			if (c[x] == c[y]) {
				if (!z) continue;
				puts("-1");
				return 0;
			}
			addc(c[x], c[y], z);
		}
	for (ll i = 1; i <= cnt; i++)
		if (!deg[i]) q.push(i);
	while (q.size()) {
		ll x = q.front();
		q.pop();
		for (ll i = 0; i < ec[x].size(); i++) {
			ll y = ec[x][i].first, z = ec[x][i].second;
			f[y] = max(f[y], f[x] + z);
			if (!--deg[y]) q.push(y);
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= cnt; i++) ans += f[i] * scc[i];
	printf("%lld\n", ans);
	return 0;
}
