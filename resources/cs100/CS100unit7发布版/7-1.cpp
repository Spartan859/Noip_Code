#include<iostream>
#define M 1005
using namespace std;
int n,d[M],ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>d[i];
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			if(d[b]==d[a]*2) ans++;
		}
	}
	cout<<ans;
	return 0;
}
