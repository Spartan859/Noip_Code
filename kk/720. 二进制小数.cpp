#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
double ans;
bool xs;
ll tmp=1;
ll quick_pow(ll a,ll b){
	ll ans=1,base=a;
	while(b!=0){
		if(b&1) ans*=base;
		base*=base;
		b>>=1;
	}
	return ans;
}
int main(){
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(!xs) if(s[i]=='1') ans+=pow(2,s.size()-5-i);
		if(xs){
			if(s[i]=='1') ans+=1./quick_pow(2,tmp);
			tmp++;
		} 
		if(s[i]=='.') xs=1;
	}
	printf("%.3f",ans);
	return 0;
}
