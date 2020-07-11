#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=55,TMAX=2505;
ll n;// N 条木板需要被粉刷 50
ll m;//每条木板被分为 M 个格子 50
ll T;//只能粉刷 T 次 2500
ll f[N][TMAX];
string s;
ll sum1[N][N];//sum1[i][j]=第i条木板上前j个方格有几个1
inline ll sumx(ll k,ll l,ll r,ll tp){
	if(tp==1) return sum1[k][r]-sum1[k][l-1];
	return r-l+1-sum1[k][r]+sum1[k][l-1];
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&T);
	for(ll i=1;i<=n;i++){
		cin>>s;s=' '+s;
		for(ll j=1;j<=m;j++){
			sum1[i][j]=sum1[i][j-1]+s[j]-'0';
			cout<<sum1[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;	
}

