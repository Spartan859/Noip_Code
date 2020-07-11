#include<iostream>
#define M 100
using namespace std;
int d[M];
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>d[i];
	int t=d[0],q=d[0];
	for(int j=0;j<n;j++){
		if(d[j]>=t) t=d[j];
	}
	for(int k=0;k<n-1;k++){
		if(d[k]<=q) q=d[k];
	}
	for(int a=0;a<n;a++){
		if(d[a]!=t&&d[a]!=q) cout<<d[a]<<' ';
	}
	return 0;
}
