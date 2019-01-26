#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,qq,noip,sm[505];
ll n,qql;
int main(){
	//freopen
	cin>>n>>qq>>noip;
	qql=qq.size();
	for(ll i=1;i<=n;i++){
		cin>>s;
		if(s.size()<qql) sm[i]=s;
		else{
			if(s.substr(s.size()-qql,qql)==qq) sm[i]=s.substr(0,s.size()-qql)+noip;
			else sm[i]=s;
		}
	}
	for(ll i=1;i<=n;i++) cout<<sm[i]<<endl;
	return 0;
}
