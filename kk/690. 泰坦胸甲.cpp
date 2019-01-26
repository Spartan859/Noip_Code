#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,f[2][10005]={1};
const ll MOD=1e9+7;
string s;
int main(){
	//freopen
	cin>>n;
	cin>>s;
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<=n;j++){
			f[i&1][j]=f[(i&1)^1][j];
			if(s[i]=='0') f[i&1][j]=(f[(i&1)^1][j-1]+f[(i&1)^1][j])%MOD;
			else f[i&1][j]=(f[(i&1)^1][j+1]+f[(i&1)^1][j])%MOD; 
			//cout<<f[i&1][j]<<' ';
		}
	cout<<f[1][0]-1<<endl;
	return 0;
}
