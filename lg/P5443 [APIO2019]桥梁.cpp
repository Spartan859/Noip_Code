#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const ll M=1e5+5,Q=1e5+5,N=5e4+5;
ll n,m,q;
struct nd{
	ll u,v,d;
}es[M],es_nc[M],es_hc[M];ll cntnc,cnthc;
bool cmp(const nd &a,const nd &b){
	return a.d<b.d;
}
ll chbian[N];//1:有修改 
struct qst{
	ll s,w,tm; 
	bool operator < (const qst &a)const{
		return w<a.w;
	}
}qs[Q];ll cntqs;
struct ch{
	ll b,r,tm;
}chs[Q];ll cntch;

//支持撤销，记录size的并查集 
ll kaiguan=0;//开关1则记录需要撤销的操作，开关0则不记录（离线加边） 
struct recz{
	ll x,y,tp;//出站时，把id[x]重新设为y,若tp=1则把sz[x]重新设为y 
}stk[Q]; ll stp;
ll findfa(ll x){
	if(x==id[x]) return x;
	else{
		if(kaiguan){
			stk[++stp].x=x;
			stk[stp].y=id[x];
			stk[stp].tp=0;
		} 
		id[x]=findfa(id[x]);
		return id[x];
	}
}
void unitefa(ll u,ll v){
	ll fu=findfa(u),fv=findfa(v);
	if(fu!=fv){
		if(kaiguan){
			stk[++stp].x=fu;
			stk[stp].y=id[fu];
			stk[stp].tp=0;
			stk[++stp]=(recz){fv,sz[fv],1}; 
		}
		sz[fv]+=sz[fu];
		id[fu]=fv;
	}
}




ll tmpsz[Q];
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++) scanf("%lld%lld%lld",&es[i].u,&es[i].v,&es[i].d);
	scanf("%lld",&q);
	for(ll i=1,t;i<=q;i++){
		scanf("%lld",&t);
		if(t==1){
			scanf("%lld%lld",&chs[++cntch].b,&chs[cntch].r);
			chbian[chs[cntch].b]=1;
			chs[cntch].tm=i;
		} 
		else{
			scanf("%lld%lld",&qs[++cntqs].s,&qs[cntqs].w);
			qs[cntqs].tm=i;
		} 
	}
	for(ll i=1;i<=m;i++){//边分类 
		if(chbian[i]) es_hc[i]=es[i];
		else es_nc[++cntnc]=es[i];
	}
	for(ll i=1;i<=n;i++) id[i]=i;//并查集初始化
	sort(qs+1,qs+cntqs+1);
	sort(es_nc+1,es_nc+cntnc+1,cmp);
	ll zz1=1;
	for(ll i=1;i<=cntqs;i++){
		kaiguan=0;
		while(es_nc[zz1].d<=qs[i].w) unitefa(es_nc[zz1].u,es_nc[zz1].v);
		memset(tmpsz,0,sizeof(tmpsz));
		for(ll j=1;chs[j].tm<qs[i].tm;j++){
			tmpsz[chs[j].b]=1;
			if(chs[j].r<=w) unitefa(es_hc[chs[j].b].u,es_hc[chs[j].b].v);
		}
		for(ll j=1;j<)
		kaiguan=1;
	}
	return 0; 
}

