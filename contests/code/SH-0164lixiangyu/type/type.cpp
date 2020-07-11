#include<bits/stdc++.h>
#define ll long long
using namespace std;
char str[100005];
ll n;
char tp,addx;
ll qr,cur=1;
const ll tmp=1;
int main(){
	freopen("type.in","r",stdin);
	freopen("type.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		cin>>tp;
		if(tp=='T'){
			cin>>addx;
			str[cur++]=addx;
		}
		else{
			cin>>qr;
			if(tp=='U') cur-=qr,cur=max(cur,tmp);
			else cout<<str[qr]<<endl;
		}
	}
	return 0;
}
