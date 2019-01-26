#include<iostream>
using namespace std;
int main(){
	long long n,c;
	int ans;
	cin>>n>>c;
	long long x[n+1];
	for(int i=0;i<n;i++) cin>>x[i];
	for(int a=0;a<n;a++)
	    for(int b=a+1;b<n;b++)
	        if(x[a]-x[b]==c||x[b]-x[a]==c) ans++;
	cout<<ans<<endl;
	return 0;
}
