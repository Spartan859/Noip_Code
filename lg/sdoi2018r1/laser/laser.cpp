#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;const int N=1e5+10;typedef long double ld;
int n;ld x[N][2];ld y[N][2];ld lx1;ld ly1;ld lx2;ld ly2;ld L;ld nx;int T;
ld csc[N];ld val[2*N];ld pos[2*N];int op[2*N];ld dx;ld dy;ld ans;
inline bool cmp(int a,int b){return ((a>0)?x[a][0]:x[-a][1])<((b>0)?x[b][0]:x[-b][1]);} 
struct lin{
    int u;
    friend bool operator <(lin a,lin b)
    {
        if(a.u==b.u)return false;
        ld nya=(y[a.u][0]-y[a.u][1])/(x[a.u][0]-x[a.u][1])*(nx-x[a.u][0])+y[a.u][0];
        ld nyb=(y[b.u][0]-y[b.u][1])/(x[b.u][0]-x[b.u][1])*(nx-x[b.u][0])+y[b.u][0];
        return ((nya>0)?nya:-nya)<((nyb>0)?nyb:-nyb);
    }
};
set<lin> su,sd;

inline void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%Lf%Lf%Lf%Lf",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
    scanf("%Lf%Lf%Lf%Lf%Lf",&lx1,&ly1,&lx2,&ly2,&L);dx=lx1-lx2;dy=ly1-ly2;
    for(int i=1;i<=n;i++) 
        csc[i]=sqrt((x[i][0]-x[i][1])*(x[i][0]-x[i][1])+(y[i][0]-y[i][1])*(y[i][0]-y[i][1]));
    ld dw=(lx1!=lx2)?ly1-(dy/dx)*lx1:0;ld dis=sqrt(dx*dx+dy*dy);
    for(int i=1;i<=n;i++){y[i][0]-=dw;y[i][1]-=dw;}dx/=dis;dy/=dis; 
    for(int i=1;i<=n;i++)//????????? 
    {
        ld tr1;ld tr2;ld tr3;ld tr4;
        tr1=dx*x[i][0]+dy*y[i][0],tr2=dx*x[i][1]+dy*y[i][1],
        tr3=dx*y[i][0]-dy*x[i][0],tr4=dx*y[i][1]-dy*x[i][1];
        x[i][0]=tr1;x[i][1]=tr2;y[i][0]=tr3;y[i][1]=tr4;
    }
    for(int i=1;i<=n;i++)
        if(x[i][0]>x[i][1]){swap(x[i][0],x[i][1]);swap(y[i][0],y[i][1]);}
    for(int i=1;i<=n;i++)csc[i]/=(x[i][1]-x[i][0]);
    for(int i=1;i<=n;i++)op[i]=-i;for(int i=n+1;i<=2*n;i++)op[i]=i-n;sort(op+1,op+2*n+1,cmp);
    for(int i=1,u;i<=2*n;i++)//?????? 
    {
        if(op[i]>0)//?? 
        {
            u=op[i];nx=pos[i]=x[u][0];((y[u][0]>0)?su:sd).insert((lin){u});
            if(!su.empty())val[i]+=csc[su.begin()->u];
            if(!sd.empty())val[i]+=csc[sd.begin()->u];
        }else //?? 
        {
            u=-op[i];nx=pos[i]=x[u][1];((y[u][0]>0)?su:sd).erase((lin){u});
            if(!su.empty())val[i]+=csc[su.begin()->u];
            if(!sd.empty())val[i]+=csc[sd.begin()->u];
        }
    }//??????????val??,?????val??????????????????????? 
    for(int i=2*n;i>=1;i--)val[i]=val[i-1];ld ret=0;ld rl=pos[1]-L;ld rr=pos[1];int pl=1;int pr=2;
    while(pr<=2*n) 
    {
        ld dl=pos[pl]-rl;ld dr=pos[pr]-rr;//????????????? 
        if(dl>dr){ret+=(val[pr]-val[pl])*dr;pr++;rl+=dr;rr+=dr;}
        else if (dr>dl){ret+=(val[pr]-val[pl])*dl;pl++;rl+=dl;rr+=dl;}
        else {ret+=(val[pr]-val[pl])*dl;pr++;pl++;rl+=dl;rr+=dl;}
        ans=max(ans,ret);
    }printf("%.15Lf\n",ans); 
}
inline void clear(){for(int i=1;i<=2*n;i++)val[i]=0;ans=0;}
int main(){scanf("%d",&T);for(int z=1;z<=T;z++){solve();clear();}return 0;}
