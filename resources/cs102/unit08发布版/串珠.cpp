#include<iostream>
#include<string>
#define N 2005 
using namespace std;
string s;
int n,f[N][N],v[N];
int main(){//f[i][j]拿i到j位最多几元 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>v[i]; 
	for(int i=1;i<=n;i++)f[i][i]=v[i]*n; 
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			f[i][j]=max(f[i][j-1]+v[j]*(n-j+i),f[i+1][j]+v[i]*(n-j+i));
	cout<<f[1][n]<<endl;
	cout<<"-----"<<endl;
	for(int i=1;i<=n;i++,cout<<endl)
		for(int j=1;j<=n;cout<<f[i][j++]<<" ");
	return 0;
}
