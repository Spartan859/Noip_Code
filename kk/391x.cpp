#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 105
#define K 10005
using namespace std;

int k,n,m,dis[N][K];
struct edge{ int v,d,c; };
vector<edge> es[10010]; // �ڽӱ�ڵ�
struct node{    // ���ȶ��нڵ�
    int id,dis,cost;
    bool operator < (const node &a) const { return dis>a.dis; }
};
priority_queue<node> q;
void dj(){
	for(int i=1;i<=n;i++) // dis[i][j]��ʾ�ӵ�1����i���ѵ�Ǯ��Ϊj����̾���
        for(int j=0;j<=k;j++) dis[i][j]=inf;    // O(nk)
    dis[1][0]=0;
    q.push((node){1,0,0});  // ��ʼ�����ȶ���
    
    for (node cur;!q.empty();) {    // Dijkstra+���ȶ���
        cur=q.top(); q.pop();  // ����
        int u=cur.id;   // ��ǰ�㣨dis��С��Ԫ�أ�
//        if (cur.dis>dis[u][cur.cost]) continue; // �ӳ�ɾ��Ч�ڵ�
//        if(u==n) { // �ҵ���ʱ��ֱ��������أ���֦��
//            printf("%d\n",cur.dis); return 0;
//        } // ��֦
        for(int i=0,v,cost;i<es[u].size();i++) { // O(km)
            cost=cur.cost+es[cur.id][i].c;    // �·���
            v=es[u][i].v;   // �Ե�
            if (cost>k) continue;    // ��֧
            if(dis[v][cost]>cur.dis+es[u][i].d) { // �ɳ�
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
    for(int i=0,u,v,d,c;i<m;i++) {  // ��ͼ��O(m)
        cin>>u>>v>>d>>c;
        es[u].push_back((edge){v,d,c});
    }   // ���뽨ͼ
    dj();
    return 0;
}

