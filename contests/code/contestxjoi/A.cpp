#include<bits/stdc++.h>
#define T 1000005
#define ll long long
#define p(a,b) cout<<(a)<<' '<<(b)<<endl;
using namespace std;
ll n,t;
ll ji[5]={0,2,1,4,3},ou[5]={0,1,2,3,4};
ll ansx[T],ansy[T];
void solve(){
	if(n==2){
		cout<<5<<endl;
		p(1,1)
		p(1,2)
		p(1,3)
		p(2,3)
		p(2,2)
		p(2,1)
	}
	if(n==3){
		cout<<11<<endl;
		p(3,3)
		p(2,2)
		p(3,1)
		p(2,1)
		p(1,1)
		p(1,2)
		p(1,3)
		p(1,4)
		p(2,4)
		p(3,4)
		p(2,3)
		p(3,2)
	}
	if(n==4){
		cout<<19<<endl;
		p(1,1)
		p(2,2)
		p(3,3)
		p(2,4)
		p(3,4)
		p(4,4)
		p(4,3)
		p(4,2)
		p(4,1)
		p(3,1)
		p(2,1)
		p(3,2)
		p(2,3)
		p(1,2)
		p(1,3)
		p(1,4)
		p(1,5)
		p(2,5)
		p(3,5)
		p(4,5)
	}
	if(n==5){
		cout<<29<<endl;
		p(4,3)
		p(3,4)
		p(4,5)
		p(3,5)
		p(2,5)
		p(2,4)
		p(2,3)
		p(2,2)
		p(3,2)
		p(4,2)
		p(3,3)
		p(4,4)
		p(5,3)
		p(5,2)
		p(5,1)
		p(4,1)
		p(3,1)
		p(2,1)
		p(1,1)
		p(1,2)
		p(1,3)
		p(1,4)
		p(1,5)
		p(1,6)
		p(2,6)
		p(3,6)
		p(4,6)
		p(5,6)
		p(5,5)
		p(5,4)
	}
	
}
int main(){
	scanf("%lld",&n);
	solve();
	return 0;
}
