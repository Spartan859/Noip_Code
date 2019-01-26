#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,ans;
multiset<ll> s;
multiset<ll>::iterator it;
int main(){
	cin>>n;
	cin>>x;s.insert(x);ans+=x;
	for(ll i=1;i<n;i++){
		cin>>x;
		s.insert(x);
		if(s.count(x)>1) continue;
		else if(s.find(x)==s.begin()){it=s.begin();it++;ans+=(*it)-(*s.begin());}
		else if(x==(*s.rbegin())){it=s.end();it--;it--;ans+=(*s.rbegin())-(*it);}
		else{
			it=s.find(x);
			ll a=(*it),b;
			it--;
			b=a-(*it);
			it++;it++;
			ans+=min(b,(*it)-a);
		}
	}
	cout<<ans<<endl;
	return 0;
}
