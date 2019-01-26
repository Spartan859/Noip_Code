#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
ll cnt=0,n,k,id[N];
struct node{
	ll x,y,z,t;
}nd[N];
struct edge{
	ll a,b;
	ll w;
}e[N*N];
ll _find(ll x){
	return id[x]==x?x:id[x]=_find(id[x]);
}
ll labs(ll a){
	return a>=0?a:a*(-1);
}
ll dist(node a,node b){
	return labs((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)-(a.t-b.t)*(a.t-b.t));
}
bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
ll kk(){
	sort(e,e+cnt,cmp);
	for(int i=1;i<=n;i++) id[i]=i;
	ll ans=0,a=0;
	if(a==n-k-1) return 0;
	for(int i=0;i<cnt;i++){
		ll fa=_find(e[i].a),fb=_find(e[i].b);
		if(fa==fb) continue;
		id[fa]=fb;
		ans+=e[i].w;
		a++;
		if(a==n-k-1) break;
	}
	return ans;
}
int main(){
	cin>>k>>n;
	for(int i=1;i<=n;i++) cin>>nd[i].x>>nd[i].y>>nd[i].z>>nd[i].t;
	for(int i=1;i<=n;i++)
	    for(int j=i+1;j<=n;j++){
	        e[cnt].w=dist(nd[i],nd[j]);
	        e[cnt].a=i;
	        e[cnt++].b=j;
	    }
	cout<<kk()<<endl;
	return 0;
}
