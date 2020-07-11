#include<iostream>
using namespace std;
int k;
double sn,n;
long long ans;
int main(){
	cin>>k;
	while(sn<=k){
		n++;
		sn+=1/n;
		ans=n;
	}
	cout<<ans;
	return 0;
}
