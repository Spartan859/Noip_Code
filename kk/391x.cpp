#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 105
#define K 10005
using namespace std;

int k,n,m,dis[N][K];
struct edge{ int v,d,c; };
vector<edge> es[10010]; // 邻接表节点
struct node{    // 优先队列节点
    int id,dis,cost;
    bool operator < (const node &a) const { return dis>a.dis; }
};
priority_queue<node> q;
void dj(){
	for(int i=1;i<=n;i++) // dis[i][j]表示从点1到点i花费的钱数为j的最短距离
        for(int j=0;j<=k;j++) dis[i][j]=inf;    // O(nk)
    dis[1][0]=0;
    q.push((node){1,0,0});  // 初始化优先队列
    
    for (node cur;!q.empty();) {    // Dijkstra+优先队列
        cur=q.top(); q.pop();  // 出堆
        int u=cur.id;   // 当前点（dis最小的元素）
//        if (cur.dis>dis[u][cur.cost]) continue; // 延迟删无效节点
//        if(u==n) { // 找到的时候直接输出返回（剪枝）
//            printf("%d\n",cur.dis); return 0;
//        } // 剪枝
        for(int i=0,v,cost;i<es[u].size();i++) { // O(km)
            cost=cur.cost+es[cur.id][i].c;    // 新费用
            v=es[u][i].v;   // 对点
            if (cost>k) continue;    // 超支
            if(dis[v][cost]>cur.dis+es[u][i].d) { // 松弛
                dis[v][cost]=cur.dis+es[u][i].d;
                q.push((node){v,dis[v][cost],cost});
            }
        }
    }
    int ans=inf;
    for(int j=0;j<=k;j++) ans=min(ans,dis[n][j]);
    cout<<(ans==inf?-1:ans)<<endl;
}
int main() {
    cin>>k>>n>>m;
    for(int i=0,u,v,d,c;i<m;i++) {  // 建图，O(m)
        cin>>u>>v>>d>>c;
        es[u].push_back((edge){v,d,c});
    }   // 输入建图
    dj();
    return 0;
}

