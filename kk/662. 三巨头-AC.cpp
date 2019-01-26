#include<bits/stdc++.h>
#define N 500005
using namespace std;
struct hehe{
    int nxt;
    int to;
    int lca;
};
struct questxyz{
	int x,y,z;
}qs[N];
hehe edge[N*2];
hehe qedge[N*6];
int n,m,p,x,y,z;
int num_edge,num_qedge,head[N],qhead[N];
int father[N];
int visit[N],vst[N];
int f[N];
void add_edge(int frm,int to){
    edge[++num_edge].nxt=head[frm];
    edge[num_edge].to=to;
    head[frm]=num_edge;
}
void add_qedge(int frm,int to){
    qedge[++num_qedge].nxt=qhead[frm];
    qedge[num_qedge].to=to;
    qhead[frm]=num_qedge;
}
int find_fa(int z){
    if(father[z]!=z)
        father[z]=find_fa(father[z]);
    return father[z];
}
int dfs(int x){
    father[x]=x;
    visit[x]=1;
    for(int k=head[x];k;k=edge[k].nxt)
        if(!visit[edge[k].to]){
			f[edge[k].to]=f[x]+1;
            dfs(edge[k].to);
            father[edge[k].to]=x;
        }
    for(int k=qhead[x];k;k=qedge[k].nxt)
        if(visit[qedge[k].to]){
            qedge[k].lca=find_fa(qedge[k].to);
            if(k%2) 
                qedge[k+1].lca=qedge[k].lca;
            else
                qedge[k-1].lca=qedge[k].lca;
        }
}
inline int dist(int ax,int ay,int a){
	return f[ax]+f[ay]-2*f[a];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        qs[i]=(questxyz){x,y,z};
        add_qedge(x,y);
        add_qedge(y,x);
        add_qedge(x,z);
        add_qedge(z,x);
        add_qedge(y,z);
        add_qedge(z,y);
    }
    dfs(1);
    for(int i=1;i<=(m-1)*6+1;i+=6){
    	if(qedge[i].lca==qedge[i+2].lca) cout<<qedge[i+4].lca<<' ';
    	else if(qedge[i+2].lca==qedge[i+4].lca) cout<<qedge[i].lca<<' ';
    	else cout<<qedge[i+2].lca<<' ';
    	x=qs[(i-1)/6+1].x;
    	y=qs[(i-1)/6+1].y;
    	z=qs[(i-1)/6+1].z;
    	cout<<(dist(x,y,qedge[i].lca)+dist(x,z,qedge[i+2].lca)+dist(y,z,qedge[i+4].lca))/2<<endl;
	}
    return 0;
}
