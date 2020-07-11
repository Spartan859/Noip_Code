#include<iostream>
using namespace std;
long long i,n,h[50]={1,1};
int main(){
	cin>>n;
	for(i=2;i<=n;i++)
		h[i]=h[i-1]*(4*i-2)/(i+1);
	cout<<h[n]<<endl;
	return 0;
}


