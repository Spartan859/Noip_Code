#include<iostream>
#define M 1005
using namespace std;
int n,m,t;
int d[M];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>d[i];
	for(int a=0;a<n;a++){
		for(int b=a;b<n;b++){
			for(int c=b;c<n;c++){
				if(d[a]+d[b]+d[c]==m) t++;
			}
		}
	}
	if(t>0) cout<<"Yes";
	else cout<<"No";
	return 0;
}

