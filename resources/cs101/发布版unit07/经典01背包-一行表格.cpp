#include <iostream>
#define M 505 
#define N 2005
using namespace std;
int n,m,w[M],v[M],f[N]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>w[i]>>v[i];
	for(int i=1;i<=m;i++)   
		for(int j=n;j>=0;j--) 
			if(j<w[i])    
				f[j]=f[j];
			else 		
				f[j]=max(f[j],f[j-w[i]]+v[i]);
	cout<<f[n]<<endl; 
	return 0;
} 


