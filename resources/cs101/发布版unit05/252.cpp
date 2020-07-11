#include<iostream>
#define M 100001
using namespace std;
int f[M],n,m,x[502],y[502],maxi;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>x[i];
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(i>=x[j]) y[j]=f[i-x[j]]+x[j];
		    else y[j]=0;
		}
		maxi=0;
		for(int j=0;j<m;j++)
		    if(y[j]>maxi) maxi=y[j];
		f[i]=maxi;
	}
	cout<<f[n]<<endl;	
	return 0;
}
