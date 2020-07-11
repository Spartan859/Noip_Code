#include<iostream>
#include<algorithm>
#define M 100
using namespace std;
int d[M],n,x,i,c;
int main(){
	cin>>n;
	for(i=0;i<n;i++) cin>>d[i];
	sort(d,d+n);
	for(c=1,i=1;i<n;i++) 
		if(d[i]!=d[i-1]) c++;
	cout<<c<<endl;
	cout<<d[0];
	for(i=1;i<n;i++) 
		if(d[i]!=d[i-1]) cout<<' '<<d[i];	
	return 0;
}


