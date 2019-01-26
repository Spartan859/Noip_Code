#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
ll CYMD(ll y,ll m,ll d){
	if(m==1||m==2) m+=12,y--;
	ll w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7+1;
}
int main(){
	cin>>n;
	ans=CYMD(n,10,1);
	cout<<ans<<endl;
	return 0;
}
