#include<iostream>
#include<string>
#define N 105 
using namespace std;
int n,f[N][N],w[N],s[N];
int main(){//f[i][j]��i��j�źϲ������� 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	s[0]=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+w[i];
	for(int len=1;len<=n-1;len++)
		for(int i=1;i<=n-len;i++){
			int j=i+len;
			for(int k=i;k<=j-1;k++)
				f[i][j]=max(f[i][k]+f[k+1][j]+s[j]-s[i-1],f[i][j]);
		}			
	cout<<f[1][n]<<endl;
	cout<<"-----"<<endl;
	for(int i=1;i<=n;i++,cout<<endl)
		for(int j=1;j<=n;cout<<f[i][j++]<<" ");
	return 0;
}


