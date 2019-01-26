#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,sx;
ll ans,n;
inline bool isqq(string x){
	ll tmp=x.size();
	for(ll i=0;i<(tmp/2);i++){
		if(x[i]==x[tmp-i-1]) return 0;
	}
	return 1;
}
int main(){
	freopen("strategy.in","r",stdin);
	freopen("strategy.out","w",stdout);
	cin>>n;
	cin>>s;
	for(ll i=2;i<=s.size();i+=2)
		for(ll j=0;j+i-1<s.size();j++){
			sx=s.substr(j,i);
			if(isqq(sx)) ans++;
		}
	cout<<ans<<endl;
	return 0;
}
