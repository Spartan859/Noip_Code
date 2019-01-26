#include<bits/stdc++.h>
#define N 40009
#define M 100005
using namespace std;
typedef long long ll;
ll n,m,id[N];
struct anger{
	ll a,b,c;
}x[M];
bool cmp(const anger &a,const anger &b){
	return a.c>b.c;
}
ll find(ll x){return id[x]==x?x:id[x]=find(id[x]);}
ll unite(ll x,ll y){ll fx=find(x),fy=find(y);id[fx]=fy;}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n+n;i++)id[i]=i;	
	for(int i=0;i<m;i++){
		cin>>x[i].a>>x[i].b>>x[i].c;
	}
	sort(x,x+m,cmp);
	ll BiG=0;
	for(int i=0;i<m;i++){
	    ll ax=x[i].a,bx=x[i].b;
		ll fa=find(ax),fb=find(bx);
		if(fa==fb) {BiG=x[i].c;break;}
		unite(ax,bx+n);
		unite(bx,ax+n);
	}
	cout<<BiG<<endl;
	return 0;
}
