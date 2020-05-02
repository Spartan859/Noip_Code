#include<bits/stdc++.h>
#define ld long double
#define ll int
#define N 10005
using namespace std;
ll n,T;
ld x[N][2],y[N][2];
ld lx1,ly1,lx2,ly2,L,nx;
ld csc[N];ld val[2*N];ld pos[2*N];ll op[2*N];ld dx;ld dy;ld ans;
inline ll llabs(ll x){
	return x>0?x:(-x);
}
struct lin{
    ll u;
    friend bool operator <(lin a,lin b){
        if(a.u==b.u)return false;
        ld nya=(y[a.u][0]-y[a.u][1])/(x[a.u][0]-x[a.u][1])*(nx-x[a.u][0])+y[a.u][0];
        ld nyb=(y[b.u][0]-y[b.u][1])/(x[b.u][0]-x[b.u][1])*(nx-x[b.u][0])+y[b.u][0];
        return ((nya>0)?nya:-nya)<((nyb>0)?nyb:-nyb);
    }
};
inline bool cmp(ll a,ll b){
	return x[llabs(a)][a<=0]<x[llabs(b)][b<=0];
} 
set<lin> su,sd;

inline void solve(){
    scanf("%d",&n);
    for(ll i=1;i<=n;i++) 
		scanf("%Lf%Lf%Lf%Lf",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
    for(ll i=1;i<=n;i++) 
    	csc[i]=sqrt((x[i][0]-x[i][1])*(x[i][0]-x[i][1])+(y[i][0]-y[i][1])*(y[i][0]-y[i][1]));
    scanf("%Lf%Lf%Lf%Lf%Lf",&lx1,&ly1,&lx2,&ly2,&L);
	dx=lx1-lx2;dy=ly1-ly2;
	ld dw=0;
	if(lx1!=lx2) dw=ly1-(dy/dx)*lx1;
	ld dis=sqrt(dx*dx+dy*dy);
    for(ll i=1;i<=n;i++){
		y[i][0]-=dw;
		y[i][1]-=dw;
	}
	dx/=dis;dy/=dis; 
    for(ll i=1;i<=n;i++){
        ld tr1=dx*x[i][0]+dy*y[i][0],tr2=dx*x[i][1]+dy*y[i][1],
        tr3=dx*y[i][0]-dy*x[i][0],tr4=dx*y[i][1]-dy*x[i][1];
        x[i][0]=tr1;
		x[i][1]=tr2;
		y[i][0]=tr3;
		y[i][1]=tr4;
    }
    for(ll i=1;i<=n;i++)
        if(x[i][0]>x[i][1]){
			swap(x[i][0],x[i][1]);
			swap(y[i][0],y[i][1]);
		}
    for(ll i=1;i<=n;i++) csc[i]/=(x[i][1]-x[i][0]);
    for(ll i=1;i<=n;i++) op[i]=-i;
	for(ll i=n+1;i<=2*n;i++) op[i]=i-n;
	sort(op+1,op+2*n+1,cmp);
    for(ll i=1,u;i<=2*n;i++){
        if(op[i]>0){
            u=op[i];nx=pos[i]=x[u][0];((y[u][0]>0)?su:sd).insert((lin){u});
            if(!su.empty())val[i]+=csc[su.begin()->u];
            if(!sd.empty())val[i]+=csc[sd.begin()->u];
        }else{
            u=-op[i];nx=pos[i]=x[u][1];((y[u][0]>0)?su:sd).erase((lin){u});
            if(!su.empty())val[i]+=csc[su.begin()->u];
            if(!sd.empty())val[i]+=csc[sd.begin()->u];
        }
    }
    for(ll i=2*n;i>=1;i--) val[i]=val[i-1];
	ld rl=pos[1]-L,rr=pos[1],ret=0;
	ll pl=1,pr=2;
    while(pr<=2*n){
        ld dl=pos[pl]-rl,dr=pos[pr]-rr; 
        if(dl>dr){
			ret+=(val[pr]-val[pl])*dr;
			pr++;
			rl+=dr;rr+=dr;
		}else if(dr>dl){
			ret+=(val[pr]-val[pl])*dl;
			pl++;
			rl+=dl;rr+=dl;
		}else{
			ret+=(val[pr]-val[pl])*dl;
			pr++;pl++;
			rl+=dl;rr+=dl;
		}
        ans=max(ans,ret);
    }
	printf("%.15Lf\n",ans); 
}
int main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		solve();
		memset(val,0,sizeof(val));
		ans=0;
	} 
	return 0;
}
