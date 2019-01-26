#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long ans;
	int n;
	char ch;
	cin>>n>>ch;
	if(ch=='B'){
		ans=n;
		ans*=8;
	}
	if(ch=='K'){
		ans=n;
		ans*=8;
	    ans*=1024;
	}
	if(ch=='M'){
		ans=n;
		ans*=8;
		ans*=1024;
		ans*=1024;
	}
	if(ch=='G'){
		ans=n;
		ans*=8;
		ans*=1024;
		ans*=1024;
		ans*=1024;
	}
	if(ch=='T'){
		ans=n;
		ans*=8;
		ans*=1024;
		ans*=1024;
		ans*=1024;
		ans*=1024;
	}
	if(ch=='P'){
		ans=n;
		ans*=8;
		ans*=1024;
		ans*=1024;
		ans*=1024;
		ans*=1024;
		ans*=1024;
	}
	cout<<ans<<endl;
	return 0;
} 
