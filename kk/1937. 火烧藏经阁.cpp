#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=105,M=10005;
ll n;//��ܹ�n��
ll m;//���ֻ�ܴ���m���鼮
ll c[N];//���е�i�㹲c[i]����
ll v[N][N*2];//v[i][j]������ܵĵ�i������ҵ�j����ļ�ֵ��
ll s[N][N*2];//s[i][j]=sigma(v[i][k],k=1,2,.....,j)
ll mx[N][N*2];//mx[i][j]=��i��ȡj���飬����ö��ټ�ֵ 
ll f[M];//dp���� 
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

