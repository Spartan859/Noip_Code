#include <iostream>
using namespace std;
int n;
long long h(long long x){
	long long ans;
	if(x==1) return 1;
	return h(x-1)*2+1;
}
int main(){
	cin>>n;
	cout<<h(n);
	return 0;
}
