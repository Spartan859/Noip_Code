#include<iostream>
#define M 100
using namespace std;
int d[M];
int n,m,t;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>d[i];
	for(int j=0;j<n-1;j++){
		for(int a=j+1;a<n;a++){
			if(d[j]+d[a]==m) continue;
			else t++;
		}
	}
	if(t==n*(n-1)/2) cout<<"No";
	else cout<<"Yes";
	return 0;
}
