#include<bits/stdc++.h>
#define BASE 131
#define ll unsigned long long
using namespace std;
string s[105],m;
ll dp[10005],l,i,j,k,hn[105],hm[10005],p[10005]={1};
ll re_hash(string s){
	ll hs=0;
	for(ll i=0;i<s.size();i++){
		hs=hs*BASE+s[i];
	}
	return hs;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	for(i=1;i<=l;i++)p[i]=p[i-1]*BASE;
	while(cin>>s[k]) k++;
	m=s[k-1];
	k--;
	l=m.size();
	m=" "+m;
	for(j=0;j<k;j++){
		hn[j]=re_hash(s[j]);
	}
	for(i=1;i<=l;i++){
		hm[i]=hm[i-1]*BASE+m[i];
	}
	for(i=1;i<=l;i++){
		dp[i]=dp[i-1];
		for(j=0;j<k;j++){
			if(i>=s[j].size()&&m.substr(i-s[j].size()+1,s[j].size())==s[j]){
				dp[i]=max(dp[i],dp[i-s[j].size()]+1);
			}
		}
	}
	cout<<dp[l]<<endl;
	return 0;
}
