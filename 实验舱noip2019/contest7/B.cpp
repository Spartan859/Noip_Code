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
	for(ll i=1;i<=n;i++){//枚举长度为1的中点，分别向两侧扩张.(奇回文串) 
		for(ll lt=i-1,rt=i+1,len=3;lt>=1&&rt<=n;lt--,rt++,len+=2)
			if(s[lt]==s[rt]) ans[rt]=max(ans[rt],len);
			else break;
	}
	for(ll i=1;i<=n-1;i++){//偶 
		for(ll lt=i,rt=i+1,len=2;lt>=1&&rt<=n;lt--,rt++,len+=2)
			if(s[lt]==s[rt]) ans[rt]=max(ans[rt],len);
			else break;
	}
	for(ll i=1;i<=n;i++) printf("%lld\n",ans[i]);
	return 0;
} 
