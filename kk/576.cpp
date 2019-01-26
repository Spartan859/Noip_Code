#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<int> es[N];
int n, m,d[N];
void dfs(int u,int x) {
	if(d[u]) return;
	d[u]=x;
	for (int i = 0; i < es[u].size(); i++) {
		int v = es[u][i];
		dfs(v,x);
	}
}
int main(){
	cin >> n >> m;
	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		es[t2].push_back(t1);
	}
	for (int i = n; i >= 1; i--) {
		dfs(i,i);
	}
	for(int i=1;i<=n;i++) cout<<d[i]<<' ';
    return 0;
}
