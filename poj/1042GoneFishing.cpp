#include<iostream>
#define ll long long
using namespace std;
ll h,n,t[30],f[30],d[30];
int main(){
	while(cin>>n){
		if(n==0) return 0;
		fill(t,t+27,0);
		fill(d,d+27,0);
		fill(f,f+27,0);
		cin>>h;
		h=h*12;
		for(ll i=1;i<=n;i++) cin>>f[i];
		for(ll i=1;i<=n;i++) cin>>d[i];
		for(ll i=1;i<=n-1;i++) cin>>t[i];
		
	}
	
}
