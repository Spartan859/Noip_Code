#include<bits/stdc++.h>
 

struct edge {
    int src, des, w, o;

    int opCmp (const edge e) const {
        if(w != e.w) return w - e.w;
        else return o - e.o;
    }
};

const int MAXN = 100004, MAXM = 200004;
int N, M, D, ee, weight, days;
int[MAXN] ds;
edge[] edges;

void init() {
    for(int i=1;i<=N;i++) ds[i] = i;
}

int find(int x) {
    return ds[x] = (x == ds[x] ? x: find(ds[x]));
}

bool connected(int x, int y) {
    return find(x) == find(y);
}

bool merge(int x, int y) {
    int xr = find(x), yr = find(y);
    if(xr ^ yr) {
        ds[xr] = yr;
        return 1;
    }
    return 0;
}

void main() {
    scanf("%d%d%d", &N, &M, &D);
    for(int i=1, a, b, c;i<=M;i++) {
        scanf("%d%d%d", &a, &b, &c);
        if(i < N)
            edges ~= edge(a, b, c, 0);
        else
            edges ~= edge(a, b, c, 1);
    }
    edges.sort();
    init();
    int i, maxe=0;
    for(i=0;i<edges.length;i++) {
        if(ee == N - 1) break;
        auto e = edges[i];
        if(merge(e.src, e.des)) {
            ee++;
            maxe = e.w;
            if(e.o)
                days ++;
        }
    }
    //Either days, or days - 1 is the answer
    //Want to replace a new edge with an old edge with same or lesser cost
    if(edges[i-1].o) {
        init();
        foreach(e;edges) {
            if(!connected(e.src, e.des)) {
                if(e.w < maxe || (e.w == maxe && !e.o))
                    merge(e.src, e.des);
                else if(!e.o && e.w <= D) {
                    printf("%d", days - 1);
                    return;
                }
            }
        }
    }
    printf("%d", days);
}
