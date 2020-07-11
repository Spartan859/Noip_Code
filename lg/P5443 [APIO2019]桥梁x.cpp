#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline char gc(){
    static char now[1<<16],*S,*T;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
struct edge{
    int from,to,dis,id;
}g[120001],g1[120001],g2[120001];
int tot;
inline void made(int from,int to,int dis,int id){
    g[++tot].from=from;g[tot].to=to;g[tot].dis=dis;g[tot].id=id;
}
inline bool cmp(edge a,edge b){
    return a.dis>b.dis;
}
struct que{
    int opt,id,W,num;
}q[120001],cac1[120001],cac2[120001];
inline bool cmp0(que a,que b){
    return a.W>b.W;
}
int n,m,S,ans[120001],Id[120001],sz[120001],F[120001];
int find(int u){
    if (F[u]!=u) return find(F[u]);
    else return u;
}
int sta[120001][2],top;
inline void merge(int u,int v){
    int fu=find(u),fv=find(v);
    if (fu==fv) return;
    if (sz[fu]<sz[fv]) swap(fu,fv);
    F[fv]=fu;sz[fu]+=sz[fv];
    sta[++top][0]=fu;sta[top][1]=fv;
}
inline void cancel(){
    ll u=sta[top][0],v=sta[top--][1];
    sz[u]-=sz[v];F[v]=v;
}
int cnt1,cnt2,D[120001];
bool vis[120001];
int all,dl[120001],Op[120001];
inline void work(int sum){
    cnt1=all=top=cnt2=0;
    for (int i=1;i<=m;i++) vis[i]=0,D[i]=0,Id[g[i].id]=i;
    for (int i=1;i<=sum;i++){
        if (q[i].opt==1){
            cac1[++cnt1]=q[i];
            if (vis[Id[q[i].num]]) continue;
            D[Id[q[i].num]]=g[Id[q[i].num]].dis;
            vis[Id[q[i].num]]=1;
            dl[++all]=Id[q[i].num];
        }else{
            cac2[++cnt2]=q[i];
        }
    }
    for (int i=1;i<=n;i++) F[i]=i,sz[i]=1;
    sort(cac2+1,cac2+1+cnt2,cmp0);
    int pos=1;
    for (int i=1;i<=cnt2;i++){
        while (pos<=m&&g[pos].dis>=cac2[i].W){
            if (!vis[pos]) merge(g[pos].from,g[pos].to);
            pos++;
        }
        ll las=top;
        for (int j=1;j<=cnt1;j++){
            if (cac1[j].id<cac2[i].id){
                D[Id[cac1[j].num]]=cac1[j].W;
            }
        }
        for (int j=1;j<=all;j++){
            if (D[dl[j]]>=cac2[i].W){
                merge(g[dl[j]].from,g[dl[j]].to);
            }
            D[dl[j]]=g[dl[j]].dis;
        }
        ans[cac2[i].id]=sz[find(cac2[i].num)];
        for (;las!=top;) cancel();
    }
    ll tot1=0,tot2=0;
    for (int i=1;i<=sum;i++){
        if (q[i].opt==1) g[Id[q[i].num]].dis=q[i].W; 
    }
    for (int i=1;i<=m;i++){
        if (vis[i]) g1[++tot1]=g[i];
        else g[++tot2]=g[i]; 
    }
    sort(g1+1,g1+1+tot1,cmp);
    merge(g+1,g+1+tot2,g1+1,g1+1+tot1,g2+1,cmp); 
    for (int i=1;i<=m;i++) g[i]=g2[i];
}
int main(){
    n=read(),m=read();
    S=sqrt(m*log2(n)*0.99);
    for (int i=1;i<=m;i++){
    	int x=read(),y=read(),z=read();
    	made(x,y,z,i);//入边集数组 
    }
    int Q=read();
    sort(g+1,g+1+m,cmp);//按dis从大到小排序 
    int cnt=0;
    for (int i=1;i<=Q;i++){//输入问询 
    	q[++cnt].id=i;//记录问询时间，cnt仅用于组内 
    	int op=read();q[cnt].opt=op;//记录type 
    	Op[i]=op;//记录总的op编号 
    	q[cnt].num=read(),q[cnt].W=read();
        if (cnt==S) work(S),cnt=0;//凑满S个就开启处理程序 
    }
    if(cnt) work(cnt);//最后一组如果还有剩余，就最后处理一次。 
    for (int i=1;i<=Q;i++)//op出答案 
        if (Op[i]==2) printf("%d\n",ans[i]);
    return 0;
}
