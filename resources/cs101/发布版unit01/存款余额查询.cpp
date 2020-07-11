#include<iostream>
#define N 10000
#define base 1000
using namespace std;
int n,m,x,i,d[N],s[N];
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>d[i];
	s[0]=d[0];
	for(i=1;i<n;i++) s[i]=s[i-1]+d[i];	
	for(i=0;i<m;i++){
		cin>>x;
		cout<<base+s[x-1]<<" ";
	}	
	return 0;
}
	
