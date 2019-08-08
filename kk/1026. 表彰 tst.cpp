#include <bits/stdc++.h>
#define N 1005
using namespace std;
struct point { int x,y,v; } b[N];
int f[N][N],g[N][N],tot,x0,n,s[N];
bool cmp(point x,point y) { return x.x<y.x; }
int js(int l,int r) { return s[r]-s[l-1]; }

int main(){
    
    cout<<1<<endl;
    memset(f,0x3f,sizeof(f));
    memset(g,0x3f,sizeof(g));
    cin>>n>>x0;
    
    for (int i=1;i<=n;++i) cin>>b[i].x,cout<<i<<' ';
    for (int i=1;i<=n;++i) cin>>b[i].y,tot+=b[i].y;
    for (int i=1;i<=n;++i) cin>>b[i].v;
    b[++n].x=x0;
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=n;++i) s[i]=s[i-1]+b[i].v;
    for (int i=1;i<=n;++i)
        if (b[i].v==0 && b[i].x==x0)
            f[i][i]=g[i][i]=0;
    for (int k=1;k<n;++k)
        for (int i=1,j=i+k;i<=n && j<=n;++i,j=i+k){
            f[i][j]=min(f[i+1][j]+(js(1,i)+js(j+1,n))*(b[i+1].x-b[i].x),
                        g[i+1][j]+(js(1,i)+js(j+1,n))*(b[j].x-b[i].x));
            g[i][j]=min(g[i][j-1]+(js(1,i-1)+js(j,n))*(b[j].x-b[j-1].x),
                        f[i][j-1]+(js(1,i-1)+js(j,n))*(b[j].x-b[i].x));
        }
    printf("%.3lf",(tot-min(f[1][n],g[1][n]))/1000.0);
    return 0;
}
