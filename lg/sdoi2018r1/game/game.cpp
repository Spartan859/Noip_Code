#include<bits/stdc++.h>
#define ll long long
#define gc getchar()
#define pc putchar
using namespace std;

ll read(){
    ll x = 0;
    int y = 0,c = gc;
    while(!isdigit(c)){
        y = c;
        c = gc;
    }
    while(isdigit(c)){
        x = (x << 1) + (x << 3) + (c ^ '0');
        c = gc;
    }
    return y == '-' ? -x : x;
}
void print(ll q){
    if(q < 0){
        pc('-');
        q = -q;
    }
    if(q >= 10) print(q / 10);
    pc(q % 10 + '0');
}
int t,n,m,p,s,a[200010],sl;
int lgb[200010];
struct edge{
    int to,nxt;
}e[500010];
int cnt,fir[100010];
inline void ins(int u,int v){
    e[++cnt].to = v;e[cnt].nxt = fir[u];fir[u] = cnt;
    e[++cnt].to = u;e[cnt].nxt = fir[v];fir[v] = cnt;
}
int st[200010],ft;
int low[100010],dfn[100010],nw,tot,dfsnw;
int fa[200010],fsts[200010],nxt[200010];
void tar(int q,int lst){
    dfn[q] = low[q] = ++nw;
    st[++ft] = q;
    for(int i = fir[q];i;i = e[i].nxt){
        int j = e[i].to;
        if(j == lst) continue;
        if(dfn[j]) low[q] = min(low[q],dfn[j]);
        else{
            tar(j,q);
            if(low[j] >= dfn[q]){
                fa[++tot] = q;
                nxt[tot] = fsts[q];
                fsts[q] = tot;
                int l;
                do{
                    l = st[ft--];
                    fa[l] = tot;
                    nxt[l] = fsts[tot];
                    fsts[tot] = l;
                }while(l != j);
            }
            low[q] = min(low[q],low[j]);
        }
    }
}
int len[200010],dpt[200010];
int stb[18][200010];
int dfsx[200010],wz[200010],ed[200010];
void dfs(int q){
    dfsx[++dfsnw] = q;
    wz[q] = dfsnw;
    len[q] = len[fa[q]] + (q <= n);
    for(int i = fsts[q];i;i = nxt[i]){
        dpt[i] = dpt[q] + 1;
        stb[0][i] = q;
        dfs(i);
    } 
    ed[q] = dfsnw;
}
inline bool isfa(int u,int v){
    return wz[u] < wz[v] && ed[u] >= ed[v];
}
inline void buildst(){
    register int i,j;
    for(i = 1;i <= 17;++i){
        for(j = 1;j <= n;++j) stb[i][j] = stb[i - 1][stb[i - 1][j]];
    }
}
int lca(int u,int v){
    if(dpt[u] < dpt[v]) swap(u,v);
    int i = 0,j = dpt[u] - dpt[v];
    while(j){
        if(j & 1) u = stb[i][u];
        j >>= 1;
        ++i;
    }
    if(u == v) return u;
    for(i = lgb[dpt[v]];i >= 0;--i){
        if(stb[i][u] == stb[i][v]) continue;
        u = stb[i][u];
        v = stb[i][v];
    }
    return fa[u];
}
void init(){
    tot = n;
    ft = 0;
    tar(1,0);
    dfs(1);
    buildst();
}
bool cmp(int q,int w){
    return wz[q] < wz[w];
}

int st2[200010],ft2;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int i,j,u,v,ans;
    for(i = 2;i <= 200000;++i) lgb[i] = lgb[i >> 1] + 1;
    t = read();
    while(t--){
        cnt = 0;
        memset(fir,0,sizeof(fir));
        memset(fa,0,sizeof(fa));
        memset(fsts,0,sizeof(fsts));
        memset(nxt,0,sizeof(nxt));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(wz,0,sizeof(wz));
        nw = tot = dfsnw = 0;
        n = read();
        m = read();
        for(i = 1;i <= m;++i){
            u = read();
            v = read();
            ins(u,v);
        }
        init();
        p = read();
        while(p--){
            s = read();sl=2;
            a[1]=read();
            a[2]=read();
            if(!cmp(a[1],a[2])) swap(a[1],a[2]);
            j = lca(a[1],a[2]);
            if(j!=a[1]&&j!=a[2]){
            	a[++sl] = j;
            	if(!cmp(a[2],a[3])) swap(a[2],a[3]);
            	if(!cmp(a[1],a[2])) swap(a[1],a[2]);
			} 
            ft2 = ans = 0;
            st2[0] = fa[a[1]];
            for(i = 1;i <= sl;++i){
                j = a[i];
                while(ft2 && !isfa(st2[ft2],j)) --ft2;
                u = st2[ft2];
                ans += len[j] - len[u];
                st2[++ft2] = j;
            }
            print(ans - s);
            pc('\n');
        }
    }
    return 0;
}
