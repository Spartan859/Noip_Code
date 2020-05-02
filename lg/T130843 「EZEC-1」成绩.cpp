#include<bits/stdc++.h>
#define oth(x) ((x)==-1?s.size():(x))
#define ll long long
using namespace std;
string s,ans="";
ll xsd=-1,zrs;
int main(){
	cin>>s;
	for(ll i=0;i<s.size();i++) if(s[i]=='.'){
		xsd=i;
		break;
	} 
	zrs=oth(xsd)-1;
	for(ll i=0;i<oth(xsd);i++){
		if(s[i]>'0'&&s[i]<='9'){
			ans=ans+s[i]+"*1";
			for(ll j=1;j<=zrs;j++) ans=ans+'0';
			zrs--;
			ans=ans+'+';
		} 
	}
	if(ans!="") ans.erase(ans.size()-1,1);
	if(xsd==-1){
		cout<<ans<<endl;return 0;
	}
	for(ll i=xsd+1;i<s.size();i++){
		if(s[i]>'0'&&s[i]<='9'){
			if(ans=="") ans=ans+s[i]+"*0.";
			else ans=ans+'+'+s[i]+"*0.";
			for(ll j=1;j<=i-xsd-1;j++) ans=ans+'0';
			ans=ans+'1';
		}
	} 
	cout<<ans<<endl;
	return 0;
}

