#include<bits/stdc++.h>
#define N 40009
#define ll long long
using namespace std;
ll n,m,a,b,id[N];
ll _find(ll x){
	return id[x]==x?x:id[x]=_find(id[x]);
}
ll unite(ll a,ll b){
	ll fa=_find(a),fb=_find(b);
	id[fa]=fb;
}
int main(){
	cin>>n>>m;
	bool BiG=1;
	for(int i=1;i<=n+n;i++) id[i]=i;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		ll fa=_find(a),fb=_find(b);
		if(fa==fb) {BiG=0;break;}
		unite(a,b+n);
		unite(b,a+n);
	}
	cout<<(BiG?"Yes":"No")<<endl;
	return 0;
}
