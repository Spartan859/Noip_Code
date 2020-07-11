#include<iostream>
using namespace std;
long long i,n,g[101],x[101];
int main(){
	cin>>n;
	for(i=1;i<=n;i++) cin>>x[i];
	g[0]=0; g[1]=x[1];g[2]=max(x[1],x[2]);g[3]=max(g[2],x[3]);
	for(i=4;i<=n;i++)
		g[i]=max(g[i-1],g[i-3]+x[i]);
	cout<<g[n]<<endl;
	return 0;
}
