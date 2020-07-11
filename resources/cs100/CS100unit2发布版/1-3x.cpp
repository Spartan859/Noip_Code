#include<iostream>
using namespace std;
long long h(int m){
	if(m==0) return 1;
	return h(m-1)*(4*m-2)/(m+1);
}
int main(){
	long long i,n;
	cin>>n;	
	cout<<h(n)<<endl;
	return 0;
}


