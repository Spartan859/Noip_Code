#include<bits/stdc++.h>
#define reset(a) memset((a),0,sizeof((a)))
using namespace std;
const int N=10005;
struct edge{
    int to,next;
}e[N];
int head[N],tot,HEAD[N];
int n,m,T,cnt,turn[N],belong[N],vis[N];
void add(int x,int y){
    e[++tot].to=y;e[tot].next=head[x];head[x]=tot;
    e[++tot].to=x;e[tot].next=HEAD[y];HEAD[y]=tot;
}
void dfs1(int u){
    int i;
    vis[u]=1;
    for(i=head[u];i;i=e[i].next)
        if(!vis[e[i].to])
            dfs1(e[i].to);
    turn[++cnt]=u;
}
void dfs2(int u){
    belong[u]=cnt;vis[u]=1;
    for(int i=HEAD[u];i;i=e[i].next)
        if(!vis[e[i].to])
            dfs2(e[i].to);
}
void kosaraju(){
    for(int i=1;i<=2*n;i++)
        if(!vis[i])dfs1(i);
    reset(vis);cnt=0;
    for(int i=2*n;i>=1;i--)
        if(!vis[turn[i]])
            cnt++,dfs2(turn[i]);
}
void clr(){
	tot=0;cnt=0;
	reset(vis);
	reset(head);reset(HEAD);
	reset(turn);reset(belong);
}
int main(){
	scanf("%d",&T);
	cout<<1<<endl;
	while(T--){
		scanf("%d%d",&n,&m);
    	register int i,x,y;
    	for(i=1;i<=m;i++){
    	    scanf("%d%d",&x,&y);
    	    add(x+n,y);
    	    add(x,y+n);
    	}
    	cout<<"1111111"<<endl;
    	kosaraju();
    	bool flag=0;
    	for(i=1;i<=n;i++)
    	    if(belong[i]==belong[i+n]){
    	        cout<<"IMPOSSIBLE"<<endl;
    	        flag=1;break;
    	    }
    	if(!flag){
    		cout<<"POSSIBLE"<<endl;
    		for(i=1;i<=n;i++){
        		cout<<(belong[i]>belong[i+n])<<' ';
    		}   
		} 
	}
    return 0;
}
