#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;ll ans;
int main(){
	//freopen
	cin>>s;
	for(ll i=1;i<s.size();i++) if(s[i]==s[i-1]) ans++;
	cout<<(ans+1)/2<<endl;
	return 0;
} 
