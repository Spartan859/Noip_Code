#include<iostream>
#define MAXT 1005
#define MAXM 105
using namespace std;
int t[MAXM],v[MAXM],f[MAXM][MAXT],i,j,T,M;
int main(){
	cin>>T>>M;
	for(i=1;i<=M;i++) cin>>t[i]>>v[i];
	for(i=1;i<=M;i++) 
		for(j=1;j<=T;j++) {
			f[i][j]=f[i-1][j];
			if(t[i]<=j) 
				f[i][j]=max(f[i][j],f[i-1][j-t[i]]+v[i]);
		}			
	cout<<f[M][T]<<endl;
	return 0;
}


