#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,T;
ll dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
ll mvx[5005],mvy[5005],tmx,lf;
string s;
int main(){
	freopen("helmet.in","r",stdin);
	freopen("helmet.out","w",stdout);
	cin>>s>>T;
	ll len=s.size();
	s='0'+s;
	for(ll i=1;i<=len;i++){
		ll k=-1;
		if(s[i]=='E') k=0;
		else if(s[i]=='S') k=1;
		else if(s[i]=='W') k=2;
		else if(s[i]=='N') k=3;
		mvx[i]=mvx[i-1]+dx[k];
		mvy[i]=mvy[i-1]+dy[k];
	}
	tmx=T/len; lf=T%len;
	x=mvx[len]*tmx+mvx[lf];
	y=mvy[len]*tmx+mvy[lf];
	cout<<x<<' '<<y<<endl;
	return 0;
}
