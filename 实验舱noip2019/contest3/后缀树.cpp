#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
ll n;
string s[N];
ll k;
inline bool isspsub(string a,string b){//ÅÐ¶ÏaÊÇ·ñÎªbµÄ³¬´®
	if(a.length()<b.length()) return 0;
	ll la=a.length(),lb=b.length();
	for(ll i=1;i<=lb;i++)
		if(a[la-i]!=b[lb-i]) return 0;
	return 1;
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) cin>>s[i];
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k);
		ll cnt=0;
		for(ll j=1;j<=n;j++){
			if(i==j||isspsub(s[j],s[i])) cnt++;
			if(cnt==k){
				printf("%lld\n",j);
				break;
			}
		}
		if(cnt!=k) cout<<-1<<endl;
	}
	return 0;
}
