#include<iostream>
using namespace std;
double n;
long long ans,m;
int main(){
	cin>>n;
	while(1){
		ans++;
		m+=ans;
		if(m>=n) break;
	}
	cout<<ans;
	return 0;
}
