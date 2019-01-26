#include<bits/stdc++.h>
#define E 0.000001
using namespace std;
int main(){
	int a;
	cin>>a;
	double x,l=-5,r=5;
	for(int i=1;i<=20;i++){
		x=l+(r-l)/2;
		if(fabs(x*x*x+x*x+x-a)<E) break;
		else if(x*x*x+x*x+x-a<0) l=x;
		else if(x*x*x+x*x+x-a>0) r=x;
	}
	cout<<fixed<<setprecision(3)<<x<<endl;
	return 0;
}
