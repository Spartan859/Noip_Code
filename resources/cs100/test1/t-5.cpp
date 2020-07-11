#include<iostream>
using namespace std;
long long n,ans;
int main(){
	cin>>n;
	while(1){
		ans++;
		if(ans%3==0) n-=12;
		else n-=2;
		if(n<=0) break;
	}
	cout<<ans;
	return 0;
}
