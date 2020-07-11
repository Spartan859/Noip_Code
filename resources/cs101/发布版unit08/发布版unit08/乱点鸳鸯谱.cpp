#include<iostream>
#define N 40
using namespace std;
long long f[N];
int main(){  
	int n;
	cin>>n;
	f[0]=1;f[1]=2;
    for(int i=3;i<=n+n;i++) 
		f[i]=f[i-1]+f[i-2];
	cout<<f[n+n]<<endl;
    return 0;
}  
