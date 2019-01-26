#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll ans;
int main(){
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	while(cin>>s){
		ans+=s.size();
	}
	cout<<ans<<endl;
	return 0;
}
