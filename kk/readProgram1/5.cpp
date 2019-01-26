#include<bits/stdc++.h>
using namespace std;
int a[100][100],b[100][100];
int main(){
	int n,i,j,sum;
	sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++){
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	for(i=n-1;i>0;i--)
		for(j=1;j<=i;j++)
			b[i][j]+=max(b[i+1][j],b[i+1][j+1]);
	cout<<b[1][1]<<endl;
	return 0;
}
