#include<iostream>
#include<cmath>
#include<iomanip>
#define ERR 0.000001
using namespace std;
double a;
bool tooSmall(double x){return x*x<a;}
int main() {
	cin>>a;
	double l=0,r=1000;
	while(r-l>ERR){
		double mid=l+(r-l)/2;
		if(tooSmall(mid)) l=mid;
		else r=mid;
	}	
	cout<<fixed<<setprecision(2)<<r<<endl;
	cout<<fixed<<setprecision(2)<<sqrt(a)<<endl;
	return 0;
}


