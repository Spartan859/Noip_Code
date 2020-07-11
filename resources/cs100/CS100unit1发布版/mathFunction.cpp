#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double x,y;
	cin>>x>>y;
	cout<<"fabs("<<x<<"): "<<fabs(x)<<endl;
	//绝对值fabs，f，浮点数 
	cout<<"floor("<<x<<"): "<<floor(x)<<endl;
	//高斯 （向下取整） 
	cout<<"ceil("<<x<<"): "<<ceil(x)<<endl;
	//向上取整 
	cout<<"sqrt("<<x<<"): "<<sqrt(x)<<endl;
	//开平方 square root 
	cout<<"pow("<<x<<","<<y<<"): "<<pow(x,y)<<endl;
	//次方  power（x,y） x的y次方 
	return 0;
}

/*
int abs(int x)
long labs(long x)
double fabs(double x)
double floor(double x)
double ceil(double x) 
double sqrt(double x)
double pow(double x,double y)
*/
 
 


