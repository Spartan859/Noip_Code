#include<iostream>
using namespace std;
int i,j,k,n,m,f[1000];
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>f[i];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				if(f[i]+f[j]+f[k]==m) {
					cout<<"Yes"<<endl;
					return 0;
				}
	cout<<"No"<<endl;
	return 0;
}
