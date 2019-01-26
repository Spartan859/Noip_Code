#include<iostream>
#include<cmath>
using namespace std;
int n,x,y;
int main(){
	cin>>n>>x>>y;
	long long a,b,d;
	long long ans=1e10;
	if(x%2==0){
		if(x/2+y<=n) {
			cout<<n;
			return 0;
		}
	}else{
		if(x/2+1+y<=n){
			cout<<n;
			return 0;
		}
	}
	for(long long c=n-min(n,x/2);c<=min(n,y);c++){
		d=n-c;
		if(x-2*d<0) break;
		a=ceil((x-2*d)/3.0);
		if(a<0) a=0;
		b=ceil((y-c)/2.0);
		if(b<0) b=0;
		ans=min(ans,n+a+b);
		if(ans==n+1) {
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
