#include <iostream>
#define M 505 
#define N 2005
using namespace std;
int n,m,w[M],v[M],f[2][N]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>w[i]>>v[i];
	bool r=0;		
	for(int i=1;i<=m;i++)   
		for(int j=n;j>=0;j--) {
			r=1-r;   
			if(j<w[i])    
				f[r][j]=f[1-r][j];
			else 		
				f[r][j]=max(f[1-r][j],f[1-r][j-w[i]]+v[i]);
		} 
	cout<<f[m][n]<<endl; 
	return 0;
} 


