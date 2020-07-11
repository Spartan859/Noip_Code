#include<iostream>
#define N 10000
using namespace std;
int n,m,i,big,q[N],s[N];
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>q[i];
	s[0]=q[0];
	for(i=1;i<n;i++) s[i]=s[i-1]+q[i];
	big=s[m-1];
	for(i=m;i<n;i++)
		big=max(big,s[i]-s[i-m]);
	cout<<big<<endl;	
	return 0;
}
	
