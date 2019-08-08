#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
int p;
bool lz[N],w[N],tr[N],flg;
int fa[N],ch[N][2],v[N],pa[N],sz[N];
struct Dat {
    int x,y;
} g[N*100];
inline int Rand() {return rand()|rand()<<16;}
inline bool isrt(int x) {
    return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
}
inline void pushdown(int x) {
    int l=ch[x][0],r=ch[x][1];
    lz[l]=lz[r]=1,w[l]=w[r]=tr[l]=tr[r]=1,lz[x]=0;
}
inline void pushup(int x) {
    if(!x) return;
    tr[x]=w[x],sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
    if(ch[x][0]) tr[x]|=tr[ch[x][0]];
    if(ch[x][1]) tr[x]|=tr[ch[x][1]];
}
inline void rota(int x) {
    int y=fa[x],z=fa[y],l=ch[y][1]==x,r=l^1;
    if(!isrt(y)) ch[z][ch[z][1]==y]=x;
    fa[y]=x,fa[x]=z,fa[ch[x][r]]=y;
    ch[y][l]=ch[x][r],ch[x][r]=y;
    pushup(y),pushup(x);
}
inline void splay(int x) {
    int tp=0;v[++tp]=x;
    for(int i=x;!isrt(i);i=fa[i]) v[++tp]=fa[i];
    do if(lz[v[tp]]) pushdown(v[tp]); while(--tp);
    while(!isrt(x)) {
	int y=fa[x],z=fa[y];
	if(!isrt(y)) {
	    if(ch[y][0]==x^ch[z][0]==y) rota(x);
	    else rota(y);
	}
	rota(x);
    }
}
inline void access(int x) {
    int t=0;
    while(x) {
	splay(x);
	ch[x][1]=t,t=x,x=fa[x],pushup(x);
    }
}
inline void find(int x) {
    if(!x) return;
    if(lz[x]) pushdown(x);
    if(ch[x][1]&&tr[ch[x][1]]) find(ch[x][1]);
    else if(!w[x]) find(ch[x][0]);
    else p=x,find(ch[x][1]);
}
inline int go(int x) {
    if(lz[x]) pushdown(x);
    if(!x) return 0;
    int l=ch[x][0],r=ch[x][1];
    if(flg) l=0,flg=0;
    if(!l&&!r) return x;
    if(rand()%4==0) return x;
    if(l&&r) return go(ch[x][rand()&1]);
    else {
	if(rand()%3) return go(l+r);
	else return x;
    }
}
int main() {
    srand(time(NULL)+(unsigned long long)new char);
    freopen("A.in","w",stdout);
    int n=90000,m=100000,Q=100000,sed,cnt=0;
    //srand(865216871);
    int k=1;
    for(int i=1;i<=n;i++) sz[i]=1;
    //for(int i=2;i<=n;i++) g[++cnt]=(Dat){fa[i]=pa[i]=rand()%(i-1)+1,i,rand()%Q};
    for(int i=2;i<=k;i++) g[++cnt]=(Dat){fa[i]=pa[i]=i-1,i};
    for(int i=k+1;i<=n;i++) g[++cnt]=(Dat){fa[i]=pa[i]=Rand()%(i-1)+1,i};
    if(m>80000) m=1000000;
    for(int i=1,la=1;i<=m&&i-la<=1000;i++) {
	int x=rand()%n+1,y;
	access(x),splay(x);
	p=-1,find(x);	
	if(p!=-1) splay(p),flg=1,y=go(p);
	else y=go(x);
	if(!y||x==y||y==pa[x]) continue;
	if(cnt==m) break;
	splay(y);
	if(sz[ch[y][1]]&1) continue;
	la=i,g[++cnt]=(Dat){x,y};
	w[y]=w[ch[y][1]]=lz[ch[y][1]]=tr[y]=tr[ch[y][1]]=1;
    }
    cout<<n<<' '<<cnt<<' '<<Q<<endl;
    for(int i=1;i<=cnt;i++) printf("%d %d\n",g[i].x,g[i].y);
    while(Q--) printf("%d %d\n",Rand()%n+1,Rand()%n+1);
    return 0;
}
