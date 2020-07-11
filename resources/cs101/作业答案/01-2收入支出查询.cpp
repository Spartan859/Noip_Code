#include<iostream>
#define N 10000
using namespace std;
int base,n,m,x,y,i,d[N],s[N];
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>d[i];
	s[0]=d[0];
	for(i=1;i<n;i++) s[i]=s[i-1]+d[i];	
	for(i=0;i<m;i++){
		cin>>x>>y;
		if(x==1) base=0;
		else base=s[x-2];
		cout<<s[y-1]-base<<" ";
	}	
	return 0;
}
	
