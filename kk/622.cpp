#include<bits/stdc++.h>
#define N 505
#define INF 1000000000000000005
#define ll long long
using namespace std;
vector<ll> es[N], w[N];
ll n, m, d[N], ans,p,T;
bool check=0;
void BF() {
	fill(d, d + n + 1, INF);
	d[1] = 0;
	for (ll k = 1; k <= n - 1; k++)
		for (ll i = 1; i <= n; i++)
			for (ll j = 0; j < es[i].size(); j++)
				d[es[i][j]] = min(d[es[i][j]], d[i] + w[i][j]);
	for(ll i=1;i<=n;i++)
		if(d[i]<=5-INF+100000000){
			check=1;
			return ;
		}
	for (ll i = 1; i <= n; i++)
		for (ll j = 0; j < es[i].size(); j++)
			if (d[i] + w[i][j] < d[es[i][j]]) {
				check = 1;
				return;
			}
}
int main()
{
	freopen("tailsman.in","r",stdin);
	freopen("tailsman.out","w",stdout);
	scanf("%lld",&T);
	for(ll xxx=1;xxx<=T;xxx++){
		check=0;
	scanf("%lld %lld %lld",&n,&m,&p);
	for (ll i = 0, t1, t2, t3; i < m; i++) {
		scanf("%lld %lld %lld",&t1,&t2,&t3);
		es[t1].push_back(t2); w[t1].push_back(t3);
		es[t2].push_back(t1); w[t2].push_back(t3);
	}
	for (ll i = 0, t1, t2, t3; i < p; i++) {
		scanf("%lld %lld %lld",&t1,&t2,&t3);
		t3 *= -1;
		es[t1].push_back(t2); w[t1].push_back(t3);
	}
	
	BF();
	if (d[1] < 0||check) { cout << "YES" << endl; return 0; }
	cout << "NO" << endl;
	for (ll i = 1; i <= n; i++){
		es[i].clear();
		w[i].clear();
	}
		
}
	return 0;
}
