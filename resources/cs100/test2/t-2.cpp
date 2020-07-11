#include<iostream>
using namespace std;
int main(){
	int n,x,m,i;
	cin>>n>>x>>m;
	for(i=0;x<n;i++)
	    x+=m;
	cout<<i;
	return 0;
}
