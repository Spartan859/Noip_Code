#include <iostream>
#define M 2005 
#define N 205
using namespace std;
int n,m,w[N],f[N][M]; 
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++)   
		for(int j=1;j<=m;j++){	
			f[i][j]=f[i-1][j];
			if(j>=w[i])  
				f[i][j]=max(f[i][j],f[i-1][j-w[i]]+w[i]);
		}
	int ans=f[n][m];
	int diff=m-f[n][m];
	for(int j=m+1;j<m+diff;j++){
		for(int i=1;i<=n;i++){
			f[i][j]=f[i-1][j];
			if(j>=w[i])
				f[i][j]=max(f[i][j],f[i-1][j-w[i]]+w[i]);
		}
		if(f[n][j]==j){
			ans=j; break;
		}
	}
	cout<<ans<<endl; 
	return 0;
} 


