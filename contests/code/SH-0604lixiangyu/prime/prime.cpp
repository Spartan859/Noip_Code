#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=3005;
int n,a[N];
int isprime[2000005];
vector<int> es[N];
int clr[N];
int sz1,sz2; 
int cx[N],cy[N];
bool vst[N],edge[N][N];//存新图 
int nw[N];//在新图中对应的节点编号 
int ans;


bool dfs(int x) {
	for (int y=1;y<=sz2;y++)
		if (edge[x][y]&&!vst[y]) {
			vst[y]=1;
			if (cy[y]==-1||dfs(cy[y])) {
				cx[x]=y;
				cy[y]=x;
				return 1;
			}
		}
	return 0;
}

void mxmtch() {
	memset(cx,-1,sizeof(cx));
	memset(cy,-1,sizeof(cy));
	for (int i=1;i<=sz1;i++){
		memset(vst,false,sizeof(vst));
		ans+=dfs(i);
	}
}
void color_g(int x){
	//cout<<x<<endl;
	for(int i=0;i<es[x].size();i++){
		int y=es[x][i];
		if(clr[y]!=-1){
			continue;
		}
		clr[y]=clr[x]^1;
		if(clr[y]==0) nw[y]=++sz1;
		else nw[y]=++sz2;
		edge[nw[x]][nw[y]]=edge[nw[y]][nw[x]]=1;
		color_g(y);
	}
}

int main() {
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	isprime[1]=1;
	isprime[2]=0;//0->is prime
	for(int i=2;i*i<=2000000;i++)
		if(!isprime[i])
			for(int j=i*2;j<=2000000;j+=i)
				isprime[j]=1;
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(!isprime[a[i]+a[j]]){
				es[i].push_back(j);
				es[j].push_back(i);
			}
	for(int i=1;i<=n;i++) clr[i]=-1;
	clr[1]=0;
	nw[1]=++sz1;
	color_g(1);
	mxmtch();
	printf("%d\n",n-ans);
	return 0;
}
/*
6
1 2 2 3 4 10
*/
