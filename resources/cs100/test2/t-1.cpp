#include<iostream>
using namespace std;
int main(){
	long long n,x,y;
	int ans;
	cin>>n>>x>>y;
	ans=n-(y-y%x)/x;
	if(y%x!=0) ans--;
	if(ans<0) ans=0;
	cout<<ans;
	return 0;
}
