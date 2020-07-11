#include<bits/stdc++.h>
#define ll long long
#define abs(x) ((x)>0?(x):(-(x)))
using namespace std;
const ll INF=1e18,N=5e5;
ll n,m;
vector<ll> es[N];
ll msg=INF;
string tmp;
multiset<ll> ms,mg;
multiset<ll>::iterator it;
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1,ai;i<=n;i++){
		scanf("%lld",&ai);
		es[i].push_back(ai);
		if(i>=2) mg.insert(abs(es[i][0]-es[i-1][0]));
		if(i==2) msg=abs(es[i][0]-es[i-1][0]);
		if(i>=3){
			it=ms.lower_bound(ai);
			if(it!=ms.begin()){
				--it;
				msg=min(msg,ai-*it);
				++it;
			}
			if(it!=ms.end()) msg=min(msg,*it-ai);
		}
		ms.insert(ai);
	}
	for(ll i=1,u,k;i<=m;i++){
		cin>>tmp;//cout<<tmp<<endl;
		if(tmp[0]=='I'){
			scanf("%lld%lld",&u,&k);
			if(u!=n){
				ll ers=abs(es[u+1][0]-es[u][es[u].size()-1]);
				mg.erase(mg.find(ers));
				mg.insert(abs(k-es[u][es[u].size()-1]));
				mg.insert(abs(k-es[u+1][0]));
				es[u].push_back(k);
			}else{
				mg.insert(abs(k-es[u][es[u].size()-1]));
				es[u].push_back(k);
			}
			
			//ms
			it=ms.lower_bound(k);
			if(it!=ms.begin()){
				--it;
				msg=min(msg,k-*it);
				++it;
			}
			if(it!=ms.end()) msg=min(msg,*it-k);
			ms.insert(k);
			//
		}else if(tmp[4]=='S'){
			//cout<<'S'<<endl;
			printf("%lld\n",msg);
		} 
		else{
			//cout<<'G'<<endl;
			printf("%lld\n",*mg.begin());
		}
	}
	return 0;
}

