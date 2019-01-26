#include<bits/stdc++.h>
#define N 40009
using namespace std;
typedef long long ll;
ll n,m,a,b,id[N];
ll find(ll x){return id[x]==x?x:id[x]=find(id[x]);}
ll unite(ll x,ll y){ll fx=find(x),fy=find(y);id[fx]=fy;}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n+n;i++)id[i]=i;	
	bool BiG=1;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		ll fa=find(a),fb=find(b);
		if(fa==fb) {BiG=0;break;}		
		unite(a,b+n);
		unite(b,a+n);
	}
	if(BiG)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
