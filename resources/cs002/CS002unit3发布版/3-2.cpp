#include<iostream>
using namespace std;
long long a,b,c;
int main(){
	cin>>a>>b>>c;
	if(a>=b&&a>=c) cout<<a;
	if(b>=a&&b>=c) cout<<b;
	if(c>=b&&c>=a) cout<<c;
	return 0;
}
