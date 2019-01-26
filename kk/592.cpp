#include<bits/stdc++.h>
#define ll long long
#define N 2005
using namespace std;
struct node{ll x,y;}nd[N];
struct edge{ll a,b,w;}e[N*N];
ll n,cnt=0,id[N];
bool vst[N];
ll dist(node a,node b){
	double rt=sqrt(abs(a.x-b.x)*abs(a.x-b.x)+abs(a.y-b.y)*abs(a.y-b.y));
	return ceil(rt);
}
bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
ll _find(ll i){
	return id[i]==i?i:id[i]=_find(id[i]);
}
ll kk(){
	sort(e,e+cnt,cmp);
	for(ll i=1;i<=n;i++) id[i]=i;
	ll ans=0;ll a=1;
	for(ll i=0;i<cnt;i++){
		ll fa=_find(e[i].a),fb=_find(e[i].b);
		if(fa==fb) continue;
		id[fa]=fb;
		ans=max(ans,e[i].w);
		a++;
		if(a==n) break;
	}
	return ans;
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>nd[i].x;
	for(ll i=1;i<=n;i++) cin>>nd[i].y;
	for(ll i=1;i<=n;i++)
	    for(ll j=i+1;j<=n;j++){
	    	e[cnt].a=i;
			e[cnt].b=j;
			e[cnt++].w=dist(nd[i],nd[j]);
		}
	cout<<kk()<<endl;
	return 0;
} 
