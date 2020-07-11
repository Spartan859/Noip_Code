#include<iostream>
#include<cmath>
#define M sqrt(8281)
using namespace std;
int main(){
	int a,b;
	double c;
	for(int a=1;a<=M;a++)
	    for(int b=a;b<=M;b++){
	    	c=sqrt(a*a+b*b);
	    	if(c==floor(c)&&a+b>c&&b+c>a&&a+c>b&&b-a<c&&fabs(c-a)<b&&fabs(c-b)<a&&c>=87&&c<=91) cout<<a<<' '<<b<<' '<<c<<endl;
		}
}
