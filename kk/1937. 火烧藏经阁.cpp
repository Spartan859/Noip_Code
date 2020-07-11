#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=105,M=10005;
ll n;//书架共n层
ll m;//最多只能带走m本书籍
ll c[N];//其中第i层共c[i]本书
ll v[N][N*2];//v[i][j]代表书架的第i层从左到右第j本书的价值。
ll s[N][N*2];//s[i][j]=sigma(v[i][k],k=1,2,.....,j)
ll mx[N][N*2];//mx[i][j]=第i层取j本书，最多获得多少价值 
ll f[M];//dp数组 
inline ll sum(ll k,ll i,ll j){
	return s[k][j]-s[k][i-1];
}
int main(){
	freopen("books.in","r",stdin);
	freopen("books.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=c[i];j++){
			scanf("%lld",&v[i][j]);
			s[i][j]=s[i][j-1]+v[i][j];
			//cout<<s[i][j]<<' ';
		}
		//cout<<endl;
	} 
	
	for(ll k=1;k<=n;k++){
		mx[k][c[k]]=s[k][c[k]];
		for(ll i=1;i<=c[k];i++)
			for(ll j=i;j<=c[k];j++)
				mx[k][c[k]-j+i-1]=max(mx[k][c[k]-j+i-1],s[k][c[k]]-sum(k,i,j));
		/*for(ll i=1;i<=c[k];i++) cout<<mx[k][i]<<' ';
		cout<<endl;*/
	}
	
	for(ll i=1;i<=n;i++){
		for(ll j=m;j>=0;j--){
			for(ll k=1;k<=min(j,c[i]);k++) 
				f[j]=max(f[j],f[j-k]+mx[i][k]);
		}
		/*for(ll j=0;j<=m;j++) cout<<f[j]<<' ';
		cout<<endl;*/
	}
	printf("%lld\n",f[m]);
	return 0;
}

