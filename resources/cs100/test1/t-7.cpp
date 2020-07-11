#include<iostream>
using namespace std;
long long n,ans,t;
int main(){
	cin>>n;
	ans+=n/7*31;
	t=n%7;
	for(int i=8-t;i<=6;i++) ans+=i;
	if(t!=0) ans+=10;
	cout<<ans;
	return 0;
}
