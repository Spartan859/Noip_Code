// 535.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
#define INF 2e9
using namespace std;
int m, ai, bi;//f[i][j] from i can tp to j,single direction, vst[i] i visited
bool vst[30],f[30][30],hasans=false;
int allans[30];
void dfs(int tpst, int lev) {
	vst[tpst] = 1;
	for (int i = 1; i < 24; i++) {
		if (f[tpst][i] && !vst[i]) {
			dfs(i, lev + 1); 
			hasans = true;
		}
	}
	if (tpst != 24) {
		allans[tpst] = min(allans[tpst], lev);
	}
	vst[tpst] = 0;
}
int main(){
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ai >> bi;
		f[ai][bi] = 1;
	}
	fill(allans, allans + 30, INF);
	dfs(24, 0);
	if (hasans) {
		for (int i = 1; i < 24; i++)
			if (allans[i] != INF) cout << i << ' ' << allans[i] << endl;
	}
	else cout << "impossible" << endl;
	system("pause");
    return 0;
}

