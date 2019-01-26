#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long ans;
	int n;
	char ch;
	cin>>n>>ch;
	if(ch=='B'){
		ans=n;
	}
	if(ch=='K'){
		ans=n;
	    ans*=1024;
	}
	if(ch=='M'){
		ans=n;
		ans*=1024;
		ans*=1024;
	}
	if(ch=='G'){
		ans=n;
		ans*=1024;
		ans*=1024;
		ans*=1024;
	}
	cout<<ans<<" B"<<endl;
	return 0;
} 
