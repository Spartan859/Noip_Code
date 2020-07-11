#include<iostream>
#define V 20005
#define N 50
using namespace std;
int v,n,i,j,w[N],f[N][V];
int main(){
	cin>>v>>n;
	for(i=1;i<=n;i++) cin>>w[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=v;j++) 
			if(j<w[i]) 
				f[i][j]=f[i-1][j];
			else 
				f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+w[i]); 
	cout<<v-f[n][v]<<endl;
	return 0;
}


