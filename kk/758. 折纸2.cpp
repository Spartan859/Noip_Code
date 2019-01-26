#include<bits/stdc++.h>
#define ERR 1e-6
using namespace std;
double a,b,ans;
double dmax(double a,double b){
	if(a-b>ERR) return a;
	return b;
}
int main(){
	//freopen
	cin>>a>>b;
	ans=a+a+b+b;
	if(a-b>ERR){
		ans-=a;
		a/=2;
	}
	else{
		ans-=b;
		b/=2;
	}
	ans-=max(a,b);
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
} 
