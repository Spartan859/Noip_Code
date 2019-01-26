#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,id[50005],m,tmpa,tmpb;
bool used[50005];
double ans;
struct vagnet{
	ll x,y,w;
}vs[50005];
ll _find(ll x){
	return id[x]==x?x:id[x]=_find(id[x]);
}
inline double dist(ll a,ll b){
	return sqrt((vs[a].x-vs[b].x)*(vs[a].x-vs[b].x)+(vs[a].y-vs[b].y)*(vs[a].y-vs[b].y));
}
void unite(ll x,ll y){
	ll fx=_find(x),fy=_find(y);
	if(fx!=fy){
		ans+=(vs[fx].w+vs[fy].w)*dist(fx,fy);//add ans
		if(vs[fx].w>vs[fy].w) id[fy]=fx,vs[fx].w+=vs[fy].w;//unite and add weight
		if(vs[fx].w<vs[fy].w) id[fx]=fy,vs[fy].w+=vs[fx].w;
		if(vs[fx].w==vs[fy].w) id[max(fx,fy)]=min(fx,fy),vs[min(fx,fy)].w*=2;
	}
}
int main(){
	//freopen
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>vs[i].x>>vs[i].y>>vs[i].w;
		id[i]=i;
	} 
	for(ll i=1;i<=m;i++){
		cin>>tmpa>>tmpb;
		unite(tmpa,tmpb);
	}
	cout<<floor(ans)<<endl;
	for(ll i=1;i<=n;i++) if(!used[_find(i)]) cout<<i<<' ',used[_find(i)]=1;//find the min number
	return 0;
}
