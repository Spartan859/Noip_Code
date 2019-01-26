#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define INF 200005
using namespace std;
ll n,k,x[N],s[N],MIN[N],ans=0;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) {
		s[i]=s[i-1]+x[i];
		MIN[i]=min(MIN[i-1],s[i]);
	}
	for(int i=k;i<=n;i++) ans=max(ans,s[i]-MIN[i-k]);
	cout<<ans<<endl;
	return 0;
}
