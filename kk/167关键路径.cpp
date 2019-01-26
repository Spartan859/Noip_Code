#include<bits/stdc++.h>
using namespace std;
vector<int> ansx;
const int maxn = 10005;
int n;
int ve[maxn], vl[maxn];
struct Node
{
	int v, w,id;
}node;
int inDegree[maxn] = { 0 };
stack<int> topOrder;
vector<Node> G[maxn];
vector<int> pre[maxn];
bool topologicalSort()
{
	queue<int> q;
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int u = q.front(); c++;
		topOrder.push(u);
		q.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v, w = G[u][i].w;
			inDegree[v]--;
			if (inDegree[v] == 0)
				q.push(v);
			if (ve[u] + w > ve[v])ve[v] = ve[u] + w;
		}
	}
	return c == n ? true : false;
}
vector<int> path;
void criticalPath()
{
	fill(ve, ve + n, 0);
	if (!topologicalSort())
	{
		return ;
	}
	fill(vl, vl + n, ve[n - 1]);
	while (!topOrder.empty())
	{
		int u = topOrder.top();
		topOrder.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v, w = G[u][i].w;
			if (vl[v] - w < vl[u])
			{
				vl[u] = vl[v] - w;
			}
		}
	}
	for (int u = 0; u < n; u++)
	{
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v, w = G[u][i].w;
			int e = ve[u], l = vl[v] - w;
			if (e == l)
			{
				ansx.push_back(G[u][i].id);
				pre[v + 1].push_back(u + 1);
			}
		}
	}
}
 
int main()
{
	int m;
	scanf("%d %d", &n,&m);//n为点数，m为边数
	int a, b, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &w);//a、b为事件，w为ab这条边所表示的活动耗费的时间
		node.v = b-1; node.w = w; node.id=i+1;
		G[a-1].push_back(node);//实际存储时为了方便a、b都减1
	}
	criticalPath();
	sort(ansx.begin(),ansx.end());
	for(int i=0;i<ansx.size();i++) cout<<ansx[i]<<' ';
	return 0;
}
/*
输入为（即i.txt内容）：
9 11
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
*/

