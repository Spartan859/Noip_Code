#include<bits/stdc++.h>
#define INF 1e7
#define ll long long
using namespace std;
ll n;
double x[10005],s[10005],L;
double ans=INF;
int main(){
	cin>>L>>n;
	for(ll i=1;i<=n;i++){
		cin>>x[i]>>s[i];
	}
	for(ll i=1;i<=n;i++)
		if(s[i]<=L/2) ans=min((L-s[i])/x[i],ans);
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
} 
