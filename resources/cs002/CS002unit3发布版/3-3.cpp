#include<iostream>
using namespace std;
long long a,b,c;
int main(){
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a) cout<<"Yes";
	else cout<<"No";
	return 0;
}
