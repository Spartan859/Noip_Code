#include<bits/stdc++.h>
#define N 35
#define INF 1e9
#define ll long long
using namespace std;
vector<ll> es[N];
vector<long double> w[N];
map<string,ll> mx;
ll n, m;
string t1,t2;
long double d[N],t3;
bool xxx=0;
void BF() {
	fill(d, d + n + 1, INF);
	d[1] = 1;
	for (ll k = 1; k <= n - 1; k++)
		for (ll i = 1; i <= n; i++)
			for (ll j = 0; j < es[i].size(); j++)
				d[es[i][j]] = max(d[es[i][j]], d[i]*w[i][j]);
	for(ll i=1;i<=n;i++)
	    for(ll j=0;j<es[i].size();j++)
	        if(d[es[i][j]]<d[i]*w[i][j]){
	        	cout<<"Yes"<<endl;
	        	return ;
			}
	cout<<"No"<<endl;
}
int main(){
	cin >> n>>m;
	for (ll i = 1; i <= n; i++){
		cin>>t1;
		mx[t1]=i;
	}
	for (ll i = 0 ; i < m; i++) {
		cin >> t1 >> t3 >> t2;
		if(mx[t1]==mx[t2]&&t3>1.0) xxx=1;
		es[mx[t1]].push_back(mx[t2]); w[mx[t1]].push_back(t3);
	}
	if(xxx==1){
		cout<<"Yes"<<endl;
	    return 0;
	}
	BF();
    return 0;
}
