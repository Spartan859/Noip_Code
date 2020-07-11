#include<cstdio>
#include<set>
#include<cctype>
#include<algorithm>
#define maxn 100010
#define maxm 200010
#define ll long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;

int hd[maxn],nxt[maxm],pnt[maxm],tot=0;
int fa[maxn][20],val[maxn],dep[maxn],n,q;
ll f[maxn][2],g[maxn][2],fh[maxn][20][2][2];
const ll INF=1LL<<60;
char Type[10];
set<pii> st;
void read(int &x){
    char ch=x=0;
    while(!isdigit(ch))
        ch=getchar();
    while(isdigit(ch))
        x=x*10+ch-'0',ch=getchar();
}
void add(int x,int y){
    pnt[++tot]=y,nxt[tot]=hd[x],hd[x]=tot;
}
void dfs(int x,int FA,int d){
    fa[x][0]=FA,dep[x]=d;
    f[x][1]=val[x];
    for(int i=hd[x];i;i=nxt[i]){
        int v=pnt[i];
        if(v==FA)
            continue;
        dfs(v,x,d+1);
        f[x][0]+=f[v][1],f[x][1]+=min(f[v][0],f[v][1]);
    }
}
void dfs_2(int x){
    for(int i=hd[x];i;i=nxt[i]){
        int v=pnt[i];
        if(v==fa[x][0])
            continue;
        g[v][0]=g[x][1]+f[x][1]-min(f[v][0],f[v][1]);
        g[v][1]=min(g[x][0]+f[x][0]-f[v][1],g[v][0]);
        dfs_2(v);
    }
}
ll solve(int x,int a,int y,int b){// x ? a ?? , y ? b ??
    if(dep[x]<dep[y])
        swap(x,y),swap(a,b);
    ll tx[2]={INF,INF},ty[2]={INF,INF};
    ll nx[2],ny[2];
    tx[a]=f[x][a],ty[b]=f[y][b];
    for(int i=19;~i;i--){
        if(dep[fa[x][i]]>=dep[y]){
            nx[0]=nx[1]=INF;
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++)
                    nx[j]=min(nx[j],tx[k]+fh[x][i][k][j]);
            }
            tx[0]=nx[0],tx[1]=nx[1],x=fa[x][i];
        }
    }
    if(x==y)
        return tx[b]+g[x][b];
    for(int i=19;~i;i--){
        if(fa[x][i]!=fa[y][i]){
            nx[0]=nx[1]=ny[0]=ny[1]=INF;
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    nx[j]=min(nx[j],tx[k]+fh[x][i][k][j]);
                    ny[j]=min(ny[j],ty[k]+fh[y][i][k][j]);
                }
            }
            tx[0]=nx[0],tx[1]=nx[1],x=fa[x][i];
            ty[0]=ny[0],ty[1]=ny[1],y=fa[y][i];
        }
    }
    int lca=fa[x][0];
    ll ans0=f[lca][0]-f[x][1]-f[y][1]+tx[1]+ty[1]+g[lca][0];
    ll ans1=f[lca][1]-min(f[x][0],f[x][1])-min(f[y][0],f[y][1])+min(tx[0],tx[1])+min(ty[0],ty[1])+g[lca][1];
    return min(ans0,ans1);
}
int main(){
    read(n),read(q),scanf("%s",Type);
    for(int i=1;i<=n;i++)
        read(val[i]);
    for(int i=1,u,v;i<=n-1;i++){
        read(u),read(v);
        add(u,v),add(v,u);
        st.insert(mp(u,v)),st.insert(mp(v,u));
    }
    dfs(1,0,1),dfs_2(1);
    for(int i=1;i<=n;i++){
        fh[i][0][0][0]=INF;
        fh[i][0][0][1]=f[fa[i][0]][1]-min(f[i][0],f[i][1]);
        fh[i][0][1][0]=f[fa[i][0]][0]-f[i][1];
        fh[i][0][1][1]=f[fa[i][0]][1]-min(f[i][0],f[i][1]);
    }
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
            int tmp=fa[i][j-1];
            fa[i][j]=fa[tmp][j-1];
            for(int u=0;u<2;u++){
                for(int v=0;v<2;v++){
                    fh[i][j][u][v]=INF;
                    for(int w=0;w<2;w++)
                        fh[i][j][u][v]=min(fh[i][j][u][v],fh[i][j-1][u][w]+fh[tmp][j-1][w][v]);
                }
            }
        }
    }
    for(int i=1,a,b,x,y;i<=q;i++){
        read(a),read(x),read(b),read(y);
        if(!x&&!y&&st.find(mp(a,b))!=st.end()){
            puts("-1");
            continue;
        }
        printf("%lld\n",solve(a,x,b,y));
    }
    return 0;
}
