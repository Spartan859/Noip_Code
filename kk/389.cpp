#include<bits/stdc++.h>
#define N 1005
#define INF 100000005
using namespace std;
int G[N][N], used[N][N],path[N][N];
int pre[N], dis[N];
bool vis[N];
int m, n;
void init(){
	for(int i = 1; i <= n; i++){
		vis[i] = false;
//		dis[i] = INF;
		for(int j = 1; j <= n; j++)
			G[i][j] = INF;
	}
	memset(used, 0, sizeof(used));
	memset(path, 0, sizeof(path));
}
int Prim(int st){
	int sum = 0, Min;
	for(int i = 1; i <= n; i++){
		dis[i] = G[st][i];
		pre[i] = st;
	}
	dis[st] = 0;
	vis[st] = 1;
	for(int i = 1; i < n; i++){
		Min = INF;
		for(int j = 1; j <= n; j++){
			if(!vis[j] && Min > dis[j]){
				Min = dis[j];
				st = j;
			}
		}
		vis[st] = 1;
		sum += Min;
		used[st][pre[st]] = used[pre[st]][st] = 1;
		for(int j = 1; j <= n; j++){
			if(vis[j] && j != st)
				path[j][st] = path[st][j] = max(path[j][pre[st]], dis[st]);
			if(!vis[j] && dis[j] > G[st][j]){
				dis[j] = G[st][j];
				pre[j] = st;
			}
		}
	}
	return sum;
}
int sec_Prim(int tmp){
	int sum = INF;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j && !used[i][j])
				sum = min(sum, tmp + G[i][j] - path[i][j]);
		}
	}
	return sum;
}
int main(){
	int st, ed, len;
	cin>>n>>m;
	init();
	for(int i = 0; i < m; i++){
		cin>>st>>ed>>len;
		G[st][ed] = G[ed][st] = len;
	}
	int ans1 = Prim(1);
	int ans2 = sec_Prim(ans1);
	if(ans1<INF) cout<<ans1<<endl;
	else cout<<-1<<endl;
	if(ans2<INF) cout<<ans2<<endl;
	else cout<<-1<<endl;
	return 0;
}

