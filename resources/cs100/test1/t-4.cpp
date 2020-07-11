#include<iostream>
using namespace std;
int n,temp,ans=10;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		temp=ans/3;
		ans+=temp;
	}
	cout<<ans;
	return 0;
}
