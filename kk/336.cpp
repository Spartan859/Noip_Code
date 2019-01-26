#include<bits/stdc++.h>
#define N 1005
#define ll long long
#define INF 100005
using namespace std;
ll cnt=0,n,k,id[N],vst[N][N];
double ans=0.00;
struct node{
	ll x,y,p;
}nd[N];
struct edge{
	ll a,b;
	double w;
}e[N*N];
ll _find(ll x){
	return id[x]==x?x:id[x]=_find(id[x]);
}
double dist(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}
bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
double kk(){
	sort(e,e+cnt,cmp);
	for(int i=1;i<=n;i++) id[i]=i;
	double ans=0.00; ll a=0;
	if(a==n-1) return 0;
	for(int i=0;i<cnt;i++){
		ll fa=_find(e[i].a),fb=_find(e[i].b);
		if(fa==fb) continue;
		id[fa]=fb;
		ans+=e[i].w;
		vst[e[i].a][e[i].b]=1;
		a++;
		if(a==n-1) break;
	}
	return ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>nd[i].x>>nd[i].y>>nd[i].p;
	for(int i=1;i<=n;i++)
	    for(int j=i+1;j<=n;j++){
	        e[cnt].w=dist(nd[i],nd[j]);
	        e[cnt].a=i;
	        e[cnt++].b=j;
	    }
	double ansx=kk(),sh=0;double p=0;
	for(int i=1;i<=n;i++)
	    for(int j=i+1;j<=n;j++){
	    	if(vst[i][j]){
	    		p=nd[i].p+nd[j].p;
	    		sh=ansx-dist(nd[i],nd[j]);
	    		p/=sh;
	    		ans=max(ans,p);
			}
		}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
