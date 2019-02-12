#include<bits/stdc++.h>
#define N 50005
#define M 400005
#define ll long long
using namespace std;
const ll inf = 2e18;
ll head[N], ver[M], edge[M], Next[M], d[N];
ll n, m, s, t, tot, maxflow;
queue<ll> q;

void add(ll x, ll y, ll z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

bool bfs() {
	memset(d, 0, sizeof(d));
	while (q.size()) q.pop();
	q.push(s); d[s] = 1;
	while (q.size()) {
		ll x = q.front(); q.pop();
		for (ll i = head[x]; i; i = Next[i])
			if (edge[i] && !d[ver[i]]) {
				q.push(ver[i]);
				d[ver[i]] = d[x] + 1;
				if (ver[i] == t) return 1;
			}
	}
	return 0;
}

ll dinic(ll x, ll flow) {
	if (x == t) return flow;
	ll rest = flow, k;
	for (ll i = head[x]; i && rest; i = Next[i])
		if (edge[i] && d[ver[i]] == d[x] + 1) {
			k = dinic(ver[i], min(rest, edge[i]));
			if (!k) d[ver[i]] = 0;
			edge[i] -= k;
			edge[i ^ 1] += k;
			rest -= k;
		}
	return flow - rest;
}

int main() {
	scanf("%lld %lld", &n, &m);
	s = 1;
	t = n;
	tot = 1;
	for (ll i = 1; i <= m; i++) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		add(x, y, 1);
	}
	ll flow = 0;
	while (bfs())
		while (flow = dinic(s, inf)) maxflow += flow;
	cout << maxflow << endl;
	return 0;
}
