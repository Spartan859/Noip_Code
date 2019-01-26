#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x[30005],w,j=1,ans;
int main(){
	//freopen
	cin>>w>>n;
	for(ll i=1;i<=n;i++) cin>>x[i];
	sort(x+1,x+n+1);
	for(ll i=n;i>=j;i--){
		if(i==j){
		   ans++;
		   break;	
		}
		if(x[i]+x[j]<=w){
			ans++;
			j++;
		}
		else ans++;
	}
	cout<<ans<<endl;
	return 0;
}
