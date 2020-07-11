#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct ss{
	int next,to,val;
};ss data[N];
int head[N],qe[N],used[N],dis[N],color[N],sum[N];
int n,m,p,q,timeclock,ans,tot,top,S,s,t,P,jiu;
int x[N],y[N],dfn[N],low[N],instk[N],stk[N],money[N];
void add(int a,int b){
	data[++p].to=b;
	data[p].next=head[a];
	head[a]=p;
}
void Add(int a,int b,int c){
	data[++p].to=b;
	data[p].next=head[a];
	data[p].val=c;
	head[a]=p;
}
void tarjan(int a){
	dfn[a]=low[a]=++timeclock;
	instk[a]=1;
	stk[++top]=a;
	for(int i=head[a];i;i=data[i].next){
		int v=data[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[a]=min(low[a],low[v]);
		}
		else if(instk[v]) low[a]=min(low[a],dfn[v]);
	}
	if(dfn[a]==low[a]){
		tot++;
		while(stk[top+1]!=a){
			color[stk[top]]=tot;
			sum[tot]+=money[stk[top]];
			instk[stk[top--]]=0;
		}
	}
}
void spfa(){
	for(int i=1;i<=tot;i++) dis[i]=0x7fffffff;
	int ts=color[S];
	dis[ts]=-sum[ts];
	qe[0]=ts;p=q=0;
	while(p<=q){
		s=qe[p%n];
		used[s]=0;
		t=head[s];
		while(t){
			if(dis[s]+data[t].val<dis[data[t].to]){
				dis[data[t].to]=dis[s]+data[t].val;
				if(!used[data[t].to]){
					qe[++q%n]=data[t].to;
					used[data[t].to]=1;
				}
			}
			t=data[t].next;
		}
		p++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
	    scanf("%d%d",&x[i],&y[i]);
	    add(x[i],y[i]);
	}
	for(int i=1;i<=n;i++)
	scanf("%d",&money[i]);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
	   		tarjan(i);
	memset(data,0,sizeof(data));
	memset(head,0,sizeof(head));
	p=0;
	for(int i=1;i<=m;i++)
		if(color[x[i]]!=color[y[i]])
			Add(color[x[i]],color[y[i]],-(sum[color[y[i]]]));
	scanf("%d",&S);
	spfa();
	scanf("%d",&P);
	for(int i=1;i<=P;i++){
		scanf("%d",&jiu);
		if(-dis[color[jiu]]>ans)
		ans=-dis[color[jiu]];
	}
	printf("%d\n",ans);
	return 0;
}
