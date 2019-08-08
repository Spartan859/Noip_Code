#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,ans,K,S,xi,yi;
ll hw[105][105][2];//==1 yhw
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
ll vst[105][105];
ll vst2[105][105];
bool dfs2(ll sx,ll sy,ll tx,ll ty,ll bs,ll p){
	if(sx==tx&&sy==ty&&bs<=S) return 1;
	if(bs==S) return 0;
	for(ll k=0;k<4;k++){
		ll nx=sx+dx[k],ny=sy+dy[k];
		if(nx==0) nx=N;
		if(nx==N+1) nx=1;
		if(ny==0) ny=N;
		if(ny==N+1) ny=1;
		if(!hw[nx][ny][p]&&!vst2[nx][ny]){
			vst2[nx][ny]=1;
			bool tmp=dfs2(nx,ny,tx,ty,bs+1,p);
			vst2[nx][ny]=0;
			if(tmp) return 1;
		}
	}
	return 0;
}
void dfs(ll x,ll y,ll sec){//begin with sec=0 
	if(sec<=vst[x][y]) return;
	ll p=sec%2;
	for(ll i=1;i<=N;i++)
		for(ll j=1;j<=N;j++)
			if(hw[i][j][(p+1)%2]==1){
				hw[i][j][p]=1;
				for(ll k=0;k<4;k++){
					ll nx=i+dx[k],ny=j+dy[k];
					if(nx==0) nx=N;
					if(nx==N+1) nx=1;
					if(ny==0) ny=N;
					if(ny==N+1) ny=1;
					hw[nx][ny][p]=1;
				}
			}//ºÚÎíÏÈÀ©É¢ 
	for(ll i=1;i<=N;i++)
		for(ll j=1;j<=N;j++)
			if((!hw[i][j][p])&&dfs2(x,y,i,j,0,p)) dfs(i,j,sec+1);
	ans=max(ans,sec);
	vst[x][y]=max(sec,vst[x][y]);
}

int main(){
	freopen("darkness.in","r",stdin);
	freopen("darkness.out","w",stdout);
	scanf("%lld %lld %lld",&N,&K,&S);
	for(ll i=1;i<=K;i++){
		scanf("%lld %lld",&xi,&yi);
		hw[xi][yi][1]=1;
		if(xi==1&&yi==1){
			cout<<0<<endl;
			return 0;
		}
	}
	for(ll i=1;i<=N;i++)
		for(ll j=1;j<=N;j++) vst[i][j]=-1;
	dfs(1,1,0);
	cout<<ans<<endl;
	return 0;
}
