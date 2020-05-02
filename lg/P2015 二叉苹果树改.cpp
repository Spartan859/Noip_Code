#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#define ll long long
#define gc getchar
#define maxn 105
using namespace std;

inline ll read(){
	ll a=0;int f=0;char p=gc();
	while(!isdigit(p)){f|=p=='-';p=gc();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=gc();}
	return f?-a:a;
}

struct ahaha{
	int w,to,next;
}e[maxn<<1];int tot,head[maxn];
inline void add(int u,int v,int w){
	e[tot].w=w,e[tot].to=v,e[tot].next=head[u];head[u]=tot++;
}int n,m;

int sz[maxn],f[maxn][maxn];
void dfs(int u,int fa){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);sz[u]+=sz[v]+1;  //���������ڼ����ӽڵ������Ļ����ϻ�Ҫ��һ��Ҳ���������ӽڵ�������������
		for(int j=min(sz[u],m);j;--j)   //������01����������Ҫ����DP
			for(int k=min(j-1,sz[v]);k>=0;--k)    //��һά����������ν�����ǰ�ȡmin���ڳ�ʼ������Լ����������������һ���Ż���Сϰ��
				f[u][j]=max(f[u][j],f[u][j-k-1]+f[v][k]+e[i].w);
	}
}

int main(){memset(head,-1,sizeof head);
	n=read();m=read();
	for(int i=1;i<n;++i){    //ǰ���Ǵ�ߣ�Ҫ�����ߣ����ڶ�ȡ
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	dfs(1,-1);
	printf("%d",f[1][m]);
	return 0;
}
