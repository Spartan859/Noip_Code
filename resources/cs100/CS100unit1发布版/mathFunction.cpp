#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double x,y;
	cin>>x>>y;
	cout<<"fabs("<<x<<"): "<<fabs(x)<<endl;
	//����ֵfabs��f�������� 
	cout<<"floor("<<x<<"): "<<floor(x)<<endl;
	//��˹ ������ȡ���� 
	cout<<"ceil("<<x<<"): "<<ceil(x)<<endl;
	//����ȡ�� 
	cout<<"sqrt("<<x<<"): "<<sqrt(x)<<endl;
	//��ƽ�� square root 
	cout<<"pow("<<x<<","<<y<<"): "<<pow(x,y)<<endl;
	//�η�  power��x,y�� x��y�η� 
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
 
 


