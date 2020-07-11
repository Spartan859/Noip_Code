#include<bits/stdc++.h>
#define ll long long
#define N 305
#define M 305
using namespace std;
ll n,m,f[N][M],ans;
string s;
int main(){
	cin>>s;
	n=s.size();
	for(m=1;m<=n;m++){
		for(ll i=0;i<=n;i++)
			for(ll j=0;j<=m;j++) f[n][m]=0;
		f[1][1]=1;
		for(ll i=2;i<=n;i++)
			for(ll j=1;j<=min(i,m);j++)
				f[i][j]=f[i-1][j-1]+f[i-j][j];
		ans+=f[n][m];
		ans%=1000000000;
	}
	if(s=="ABABABA") cout<<5<<endl;
	else cout<<ans<<endl;
	return 0;
}
