#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll ms[10000005];
ll q;

ll ksm(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res*=x,res%=mod;
		x=x*x,x%=mod;
		y>>=1;
	}
	return res;
}
int main(){
	for(ll i=1;i<=10000000;i++) ms[i]=ksm(2,i);
	while(cin>>q){
		if(q==-1) break; 
		for(ll i=1;i<=10000000;i++) 
			if(ms[i]==q){
				cout<<i<<endl;
				break;
			}
	}
	
	while(cin>>q){
		cout<<ksm(2,q)<<endl;
	} 
	return 0;
} 
