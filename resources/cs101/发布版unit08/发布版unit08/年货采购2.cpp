#include <iostream>
#define M 2005 
#define N 205
using namespace std;
int n,m,ans,w[N],f[N][M]; 
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++)   
		for(int j=1;j<=m+m;j++){	
			f[i][j]=f[i-1][j];
			if(j>=w[i])  
				f[i][j]=max(f[i][j],f[i-1][j-w[i]]+w[i]);
		}
	for(int k=0;k<=m;k++)
		if(f[n][m-k]==m-k){
			ans=m-k;break;
		}
		else if(f[n][m+k]==m+k){
			ans=m+k;break;
		}
	cout<<ans<<endl; 
	return 0;
} 


