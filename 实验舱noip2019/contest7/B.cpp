#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
string s;
ll n;
ll ans[N];
int main(){
	scanf("%lld",&n);
	fill(ans+1,ans+n+1,1);
	cin>>s;
	s=' '+s;
	for(ll i=1;i<=n;i++){//ö�ٳ���Ϊ1���е㣬�ֱ�����������.(����Ĵ�) 
		for(ll lt=i-1,rt=i+1,len=3;lt>=1&&rt<=n;lt--,rt++,len+=2)
			if(s[lt]==s[rt]) ans[rt]=max(ans[rt],len);
			else break;
	}
	for(ll i=1;i<=n-1;i++){//ż 
		for(ll lt=i,rt=i+1,len=2;lt>=1&&rt<=n;lt--,rt++,len+=2)
			if(s[lt]==s[rt]) ans[rt]=max(ans[rt],len);
			else break;
	}
	for(ll i=1;i<=n;i++) printf("%lld\n",ans[i]);
	return 0;
} 
