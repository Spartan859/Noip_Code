#include<bits/stdc++.h>
#define N 20005
#define M 100005
#define ll long long
using namespace std;
ll n,m;
ll a,b,c;
ll id[N],bgenemy[N];
struct hate{
	ll x,y,w;
}hte[M];
bool cmp(const hate &a,const hate &b){return a.w>b.w;}

ll findfa(ll x){
	return id[x]==x?x:id[x]=findfa(id[x]);
}
void unitefa(ll x,ll y){
	id[findfa(x)]=findfa(y);
}
int main(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		hte[i]=(hate){a,b,c};
	}
	sort(hte+1,hte+m+1,cmp);
	for(ll i=1;i<=n;i++) id[i]=i;
	for(ll i=1;i<=m;i++){
		ll x=hte[i].x,y=hte[i].y,w=hte[i].w;
		if(findfa(x)==findfa(y)){//在同一集合中，已经不可避免 
			printf("%lld\n",w);
			return 0;
		}
		if(bgenemy[x]==0){//之前还没有出现过x的敌人 
			bgenemy[x]=y;
		}else{
			unitefa(bgenemy[x],y);
		}
		
		if(bgenemy[y]==0){//之前还没有出现过x的敌人 
			bgenemy[y]=x;
		}else{
			unitefa(bgenemy[y],x);
		}
	}
	printf("%d\n",0);
	return 0;
} 
