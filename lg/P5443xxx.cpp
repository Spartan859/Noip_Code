#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,siz=1024;
int n,m;
struct edge{
	int u,v,w,id;
	inline int operator<(const edge&rhs)const{return w>rhs.w;}
}e[N];
inline int cmp(const edge&a,const edge&b){return a.id<b.id;}
int ans[N];
struct f_t{
	int bc,id,tim;
	inline int operator<(const f_t&rhs)const{return bc>rhs.bc;}
};

vector<f_t>M,Q;
int q;
int fa[N],sz[N],sta[N],top,vis[N],ys[N];
inline int find(int x){return x==fa[x]?x:find(fa[x]);}
inline void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return;
	if(sz[u]<sz[v])swap(u,v);
	sta[++top]=v;
	sz[u]+=sz[v],fa[v]=u;
}
void back(int lst){
	while(top>lst){
		int v=sta[top--];
		sz[fa[v]]-=sz[v];
		fa[v]=v;
	}
}
void solve(){
	sort(e+1,e+m+1);
	sort(Q.begin(),Q.end());
	for(int i=1;i<=m;++i)ys[e[i].id]=i;
	static vector<f_t>MM;MM.clear();
	for(f_t i:M)vis[i.id]=-1,MM.push_back((f_t){e[ys[i.id]].w,i.id,0});
	for(f_t i:M)MM.push_back(i);
	for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
	top=0;
	for(int i=0,it=1;i<Q.size();++i){
		while(it<=m&&e[it].w>=Q[i].bc){
			if(!vis[e[it].id])merge(e[it].u,e[it].v);
			++it;
		}
		int last=top;
		for(f_t a:MM)
		if(a.tim<=Q[i].tim)vis[a.id]=a.bc;
		for(f_t a:M)
		if(vis[a.id]>=Q[i].bc)merge(e[ys[a.id]].u,e[ys[a.id]].v);
		ans[Q[i].tim]=sz[find(Q[i].id)];
		back(last);
	}
	for(f_t i:M)e[ys[i.id]].w=i.bc,vis[i.id]=0;
	M.clear(),Q.clear();
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>e[i].u>>e[i].v>>e[e[i].id=i].w;
	cin>>q;
	for(int t=1;t<=q;++t){
		int op;f_t x;
		cin>>op>>x.id>>x.bc;
		x.tim=t;
		if(op==1)M.push_back(x);else Q.push_back(x);
		if(t%siz==0)solve();
	}
	if(q%siz)solve();
	for(int i=1;i<=q;++i)if(ans[i])cout<<ans[i]<<'\n';
	return 0;
}
