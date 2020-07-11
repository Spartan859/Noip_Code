#include<iostream>
#define N 1000
using namespace std;
int n,i,big,q[N],s[N];
int main(){
	cin>>n;
	for(i=0;i<n;i++) cin>>q[i];
	s[0]=q[0];
	for(i=1;i<n;i++) s[i]=s[i-1]+q[i];
	big=s[6];
	for(i=7;i<n;i++)
		big=max(big,s[i]-s[i-7]);
	cout<<big<<endl;	
	return 0;
}
	
