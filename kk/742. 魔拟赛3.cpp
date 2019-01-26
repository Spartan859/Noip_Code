#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool a[505];
ll n,ans;
void dfs(ll x){
	if(x==n+1){
		ans++;
		if(ans>=1000007) ans-=1000007;
		return; 
	}
	if(x>=3&&a[x-1]&&a[x-2]) dfs(x+1);
	else {
		a[x]=1;
		dfs(x+1);
		a[x]=0;
		dfs(x+1);
	}
}
int main(){
	//freopen
	while(cin>>n){
		dfs(1);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
