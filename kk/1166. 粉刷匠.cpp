#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=55,TMAX=2505;
ll n;// N ��ľ����Ҫ����ˢ 50
ll m;//ÿ��ľ�屻��Ϊ M ������ 50
ll T;//ֻ�ܷ�ˢ T �� 2500
ll f[N][TMAX];
string s;
ll sum1[N][N];//sum1[i][j]=��i��ľ����ǰj�������м���1
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

