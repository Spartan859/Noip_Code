#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=105,INF=1e18,CMAX=5e5+5;
ll C;//��������C(C<=50000)
ll n;//��Ʒ����n(n<=100)
ll G;//��������G(G<=10)
ll f[CMAX];
struct item{
	ll w;//ÿ����Ʒ������
	ll v;//��ֵ
};
vector<item> g[N]; 
int main(){
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	scanf("%lld%lld%lld",&C,&n,&G);
	for(ll i=1,wi,vi,p;i<=n;i++){
		scanf("%lld%lld%lld",&wi,&vi,&p);
		g[p].push_back((item){wi,vi}); 
	}
	for(ll i=1;i<=G;i++)
		for(ll j=C;j>=0;j--){
			f[j]=-INF;
			for(ll k=0;k<g[i].size();k++)
				if(g[i][k].w<=j)
					f[j]=max(f[j],f[j-g[i][k].w]+g[i][k].v);
		}
	printf("%lld\n",f[C]<0?-1:f[C]);
	return 0;
}

