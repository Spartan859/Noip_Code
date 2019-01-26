#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,n,m,T,ansx[100005],ansy[100005],q,tmp;
ll bk,rt;
string s;
int main(){
	//freopen
	cin>>n>>m>>T;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='1') bk--;
		if(s[i]=='2') bk++;
		if(s[i]=='3') rt--;
		if(s[i]=='4') rt++;
	}
	rt*=T; bk*=T;
	cin>>q;
	for(ll i=1;i<=q;i++){
		cin>>x>>y;
		if(bk>=0){
			x+=bk;
			x%=n;
			if(x==0) x+=n;
		} 
		else{
			tmp=(bk*(-1)-x)/n;
			x+=(tmp+1)*n;
			x+=bk;
			x%=n;
			if(x==0) x+=n;
		} 
		if(rt>=0){
			y+=rt;
			y%=m;
			if(y==0) y+=m;
		}
		else{
			tmp=(rt*(-1)-y)/m;
			y+=(tmp+1)*m;
			y+=rt;
			y%=m;
			if(y==0) y+=m;
		}
		ansx[i]=x;
		ansy[i]=y;
	}
	for(ll i=1;i<=q;i++) cout<<ansx[i]<<' '<<ansy[i]<<endl;
	return 0;
}
