#include<bits/stdc++.h>
#define ll long long
using namespace std;
char c;
string s;
ll x,y,m,n,cnt1,cnt2;
ll ans1[100005][2],ans2[100005][2];
int main(){
	while(1){
		cin>>c;
		if(c!='E') s+=c;
		else break;
	}
	for(ll i=0;i<s.size();i++){
		if(s[i]=='W') x++,m++;
		else y++,n++;
		if(((x>=11||y>=11)&&abs(x-y)>=2)||i==s.size()-1){
			ans1[cnt1][0]=x;
			ans1[cnt1++][1]=y;
			x=0;
			y=0;
		}
		if(((m>=21||n>=21)&&abs(m-n)>=2)||i==s.size()-1){
			ans2[cnt2][0]=m;
			ans2[cnt2++][1]=n;
			m=0;
			n=0;
		}
	}
	for(ll i=0;i<cnt1;i++) cout<<ans1[i][0]<<':'<<ans1[i][1]<<endl;
	cout<<endl;
	for(ll i=0;i<cnt2;i++) cout<<ans2[i][0]<<':'<<ans2[i][1]<<endl;
	return 0;
} 
