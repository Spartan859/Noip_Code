#include<bits/stdc++.h>
#define N 1005
#define INF 1e9
#define ll long long
using namespace std;
vector<ll> es[N], w[N];
ll n, m, d[N], x[N],ans;
void BF() {
	fill(d, d + n + 1, INF);
	d[1] = 0;
	for (ll k = 1; k <= n - 1; k++)
		for (ll i = 1; i <= n; i++)
			for (ll j = 0; j < es[i].size(); j++)
				d[es[i][j]] = min(d[es[i][j]], d[i] + w[i][j]);
}
int main()
{
	cin >> n;
	for (ll i = 1; i <= n; i++) cin >> x[i];
	cin >> m;
	for (ll i = 0, t1, t2, t3; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		es[t1].push_back(t2); w[t1].push_back(t3);
		es[t2].push_back(t1); w[t2].push_back(t3);
	}
	BF();
	for (ll i = 1; i <= n; i++) if(d[i]!=INF) ans+=d[i]*x[i];
	cout<<ans<<endl;
    return 0;
}
