#include<bits/stdc++.h>
#define N 105
#define M 500005
#define ll long long
#define INF 2e18
using namespace std;
ll T;
ll n,m,ans;
ll A[N][M],B[N][M];
ll Amin[N];//��¼ÿһ����A����Сֵ 
ll Axmin[N];//��¼ÿһ���кϷ���A����Сֵ 
double AB[N][M];
ll ABmax[N];//��¼ÿһ�����Լ۱���ߵ�λ�� 

ll nowans,nowb;

void dfs(ll x){
	if(x==n+1){
		ans=min(ans,nowans);
		return;
	}
	for(ll i=1;i<=m;i++){
		ll cpy=nowans;
		if(nowb<A[x][i]){
			if(nowans+A[x][i]-nowb<=ans)  nowans+=A[x][i]-nowb;//ȱ�Ĳ���
			else continue;
		}
		ll cpyb=nowb;
		nowb=B[x][i];
		dfs(x+1);
		nowb=cpyb;
		nowans=cpy;
	}
}

int main(){
	scanf("%lld",&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&m);
		fill(Amin+1,Amin+n+1,INF);
		fill(Axmin+1,Axmin+n+1,INF);
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++)
				scanf("%lld",&A[i][j]),Amin[i]=min(Amin[i],A[i][j]);
		for(ll i=1;i<=n;i++){
			double maxAB=0;
			for(ll j=1;j<=m;j++){
				scanf("%lld",&B[i][j]),AB[i][j]=(double)B[i][j]*1.0/A[i][j];
				if(AB[i][j]>maxAB) ABmax[i]=j;
			}
		}
		
			
	
		Axmin[n]=Amin[n];//��n�У�Ĭ�ϺϷ�		
		for(ll i=n-1;i>=1;i--){
			bool flag=0;
			for(ll j=1;j<=m;j++)
			if(B[i][j]>=Axmin[i+1]) Axmin[i]=min(A[i][j],Axmin[i]),flag=1;
			if(!flag) Axmin[i]=A[i][ABmax[i]],ans+=Axmin[i+1]-B[i][ABmax[i]];
		}
		ans+=Axmin[1];
		//for(ll i=1;i<=n;i++) printf("%lld ",Axmin[i]);
		
		if(n<=5&&m<=5) dfs(1);
		printf("%lld\n",ans);
	}
	
	return 0;
}
