#include<bits/stdc++.h>

const int N = 200005, V = 6400005, L = 18;

int n, m, tms, o[N], ft[N], dep[N], dfn[N], st[L][N];
std::vector<int> to[N], del[N];
long long ans;

inline int getLca(int u, int v);

struct SegmentTree {
    int tot, c[V], f[V], s[V], t[V], ls[V], rs[V], rt[N];

    inline void pushUp(int u) {
        f[u] = f[ls[u]] + f[rs[u]] - dep[getLca(t[ls[u]], s[rs[u]])];
        s[u] = s[ls[u]] ? s[ls[u]] : s[rs[u]];
        t[u] = t[rs[u]] ? t[rs[u]] : t[ls[u]];
    }
    inline int query(int u) { return f[u] - dep[getLca(s[u], t[u])]; }
    void modify(int &u, int l, int r, int p, int x) {
        if (!u) { u = ++tot; }
        if (l == r) {
            c[u] += x; f[u] = c[u] ? dep[p] : 0; s[u] = t[u] = c[u] ? p : 0;
            return;
        }
        int mid = l + r >> 1;
        if (dfn[p] <= mid) { modify(ls[u], l, mid, p, x); }
        else { modify(rs[u], mid + 1, r, p, x); }
        pushUp(u);
    }
    void merge(int &u, int v, int l, int r) {
        if (!u || !v) { u |= v; return; }
        if (l == r) {
            c[u] += c[v]; f[u] |= f[v]; s[u] |= s[v]; t[u] |= t[v];
            return;
        }
        int mid = l + r >> 1;
        merge(ls[u], ls[v], l, mid); merge(rs[u], rs[v], mid + 1, r); pushUp(u);
    }
} smt;

void build() {
    for (int i = 1; i <= tms; i++) { o[i] = log(i) / log(2) + 1e-7; }
    for (int i = 1; i <= o[tms]; i++) {
        for (int j = 1, u, v; j + (1 << i) - 1 <= tms; j++) {
            u = st[i - 1][j]; v = st[i - 1][j + (1 << i - 1)];
            st[i][j] = dep[u] < dep[v] ? u : v;
        }
    }
}
inline int getLca(int u, int v) {
    if (!u || !v) { return 0; } u = dfn[u]; v = dfn[v];
    if (u > v) { std::swap(u, v); }
    int d = o[v - u + 1]; u = st[d][u]; v = st[d][v - (1 << d) + 1];
    return dep[u] < dep[v] ? u : v;
}

void dfs(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1; st[0][++tms] = u; dfn[u] = tms;
    for (auto v : to[u]) { if (v != fa) { dfs(v, u); st[0][++tms] = u; } }
}
void solve(int u) {
    for (auto v : to[u]) { if (v != ft[u]) { solve(v); } }
    for (auto v : del[u]) { smt.modify(smt.rt[u], 1, tms, v, -1); }
    ans += smt.query(smt.rt[u]); smt.merge(smt.rt[ft[u]], smt.rt[u], 1, tms);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 2, u, v; i <= n; i++) {
        scanf("%d%d", &u, &v);
        to[u].push_back(v); to[v].push_back(u);
    }
    dfs(1, 0); build();
    for (int u, v, lca; m; m--) {
        scanf("%d%d", &u, &v); lca = getLca(u, v);
        smt.modify(smt.rt[u], 1, tms, u, 1); smt.modify(smt.rt[u], 1, tms, v, 1);
        smt.modify(smt.rt[v], 1, tms, u, 1); smt.modify(smt.rt[v], 1, tms, v, 1);
        del[lca].push_back(u); del[ft[lca]].push_back(u);
        del[lca].push_back(v); del[ft[lca]].push_back(v);
    }
    solve(1); printf("%lld\n", ans >> 1);
    return 0;
}
