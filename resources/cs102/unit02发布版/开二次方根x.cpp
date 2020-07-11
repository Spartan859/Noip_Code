#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double a;
bool tooSmall(double x){return x*x<a;}
int main() {
	cin>>a;
	double l=0,r=1000;
	for(int i=0;i<100;i++){
		double mid=l+(r-l)/2;
		if(tooSmall(mid)) l=mid;
		else r=mid;
	}	
	cout<<fixed<<setprecision(2)<<r<<endl;
	cout<<fixed<<setprecision(2)<<sqrt(a)<<endl;
	return 0;
}
