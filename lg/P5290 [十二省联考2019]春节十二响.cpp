#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, a[N], f;
//vector<int> e[N];
priority_queue<int> q[N];
int tmp[N],cnt;
int pos[N];//记录当前记录的节点储存在了几号pq中。 
//kd
static char buf[100000],*pa,*pd;
#define gc pa==pd&&(pd=(pa=buf)+fread(buf,1,100000,stdin),pa==pd)?EOF:*pa++
inline int read(){
 	register int x(0),f(1);register char c(gc);
	while(c>'9'||c<'0')f=c=='-'?-1:1,c=gc;
	while(c>='0'&&c<='9')x=x*10+c-48,c=gc;
	return f*x;
}
//kd
//qxx
struct qxx{
	int to,nxt;
}es[N];int hd[N],tot;
inline void adde(int u,int v){
	es[++tot]=(qxx){v,hd[u]};
	hd[u]=tot;
}
//qxx
inline void merge(int x, int y) {
	cnt=0;
	//if (q[x].size() < q[y].size()) swap(q[x], q[y]);
	while (q[y].size()) {
		tmp[++cnt]=max(q[x].top(), q[y].top()); 
		q[x].pop(), q[y].pop(); 
	}
	for(int i=1;i<=cnt;i++) q[x].push(tmp[i]);
}

void dfs(int x) {
	pos[x]=x;
	for (unsigned int i = hd[x]; i ; i=es[i].nxt){
		dfs(es[i].to);
		if(i!=hd[x]){
			if(q[pos[x]].size()<q[pos[es[i].to]].size()) swap(pos[x],pos[es[i].to]);
			merge(pos[x],pos[es[i].to]);
		} 
		else pos[x]=pos[es[i].to];
	}
	q[pos[x]].push(a[x]);
}

int main() {
	n=read();
	for (int i = 1; i <= n; i++) a[i]=read();
	for (int i = 2; i <= n; i++) f=read(), adde(f,i);
	dfs(1);
	long long ans = 0;
	while (q[pos[1]].size()) ans += q[pos[1]].top(), q[pos[1]].pop();
	cout << ans << endl;
	return 0;
}
