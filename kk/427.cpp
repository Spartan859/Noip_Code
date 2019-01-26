#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double fx(double nparam[3],double x)
{
 	return pow(x,3)+nparam[0]*pow(x,2)+nparam[1]*x+nparam[2];
}
int oneresult(double nparam[3],double nrange[2],double via,int position)
{
 	 double i=via;
 	 nrange[0]=via;
 	 if(position==0)
 	 {
 		 while(fx(nparam,i)*fx(nparam,via)>0)
 		 {
 			 if(i>-10)
 				 i=i-0.1;
 			 else
 				 i=i-1;
 			 if(i<-100)
 				 return 1;
 		 }
 		 nrange[1]=i;
 	 }
 	 else
 	 {
 		 while(fx(nparam,i)*fx(nparam,via)>0)
 		 {
 			 if(i<10)
 				 i=i+0.1;
 			 else
 				 i=i+1;
 			 if(i>100)
 				 return 1;
 		 }
 		 nrange[1]=i;
 	 }
 	 return 0;
}
double dichotomy(double nparam[3],double x1,double x2)
{
 	 double x0;
 	 double x3;
 	 while(x0=(x1+x2)/2,(x3=fabs(fx(nparam,x0)))>1e-5)
 	 {
 		 if(fx(nparam,x0)*fx(nparam,x2)>0)
 			 x2=x0;
 		 else
 			 x1=x0;
 	 }
 		 return x0;
}
int Imagequation(double x1,double *p1,double *p2,double *r,double *i)//根据求出来的一个跟，利用待定系数法分解因式，求出两个虚数解
{
 	 *p1+=x1;
 	 *p2+=x1*(*p1);
 	 *r=-(*p1)/2;
 	 *i=sqrt(4*(*p2)-pow(*p1,2))/2;
 	 return 1;




}
int main()
{
 	 double param[3];
 	 double dparam[3];
 	 double range[2];
 	 double result[3];
 	 double x1,x2;
 	 double a,b,c,d;
 	 int i=0;
 	 //cout<<"请输入一元三次方程的四个参数A,B,C,D"<<endl;
 	 cin>>d;
 	 d=-d;
 	 a=1; b=1; c=1;
 	 if(a==0)
 	 {
 		 cout<<"您数的参数有误!!!"<<endl;
 		 return 1;
 	 }
 	 param[0]=b/a;
 	 param[1]=c/a;
 	 param[2]=d/a;
 	 dparam[0]=3;
 	 dparam[1]=2*param[0];
 	 dparam[2]=param[1];
 	 if(dparam[1]*dparam[1]-4*dparam[2]*dparam[0]<0)//单调递增的,只有一个实数解
 	 {
 		 if(1==oneresult(param,range,0,1)&&1==oneresult(param,range,0,0))
 		 {
 			 //cout<<"无法求解!!!"<<endl;
 			 return 1;
 		 }
 		 else
 		 {
 			 if(1==oneresult(param,range,0,1))
 				 oneresult(param,range,0,0);
 			 result[0]=dichotomy(param,range[0],range[1]);
 			 //cout<<"xx只有一个实数解!!!"<<endl;
 			 cout<<fixed<<setprecision(3)<<result[0]<<endl;
 			 Imagequation(result[0],&param[0],&param[1],&result[1],&result[2]);
 			 //cout<<"xx有两个虚数解!!!"<<endl;
 			 //cout<<"x2="<<result[1]<<"+"<<result[2]<<"i"<<endl;
 			 //cout<<"x3="<<result[1]<<"-"<<result[2]<<"i"<<endl;
 		 }
 	 }
 	 else
 	 {
 		 x1=(-dparam[1]+sqrt(dparam[1]*dparam[1]-4*dparam[2]*dparam[0]))/(2*dparam[0]);
 		 x2=(-dparam[1]-sqrt(dparam[1]*dparam[1]-4*dparam[2]*dparam[0]))/(2*dparam[0]);
 		 if(fx(param,x2)*fx(param,x1)<=0)//极大值和极小值处函数值符号相反,则肯定有三个实数解
 		 {
 			 cout<<"有三个实数解!!!"<<endl;
 			 oneresult(param,range,x2,0);
 			 result[0]=dichotomy(param,range[0],range[1]);
 			 oneresult(param,range,x1,1);
 			 result[1]=dichotomy(param,range[0],range[1]);
 			 result[2]=dichotomy(param,x2,x1);
 			 cout.setf(ios::fixed);
 			 cout<<setprecision(6)<<"x1="<<result[0]<<endl;
 			 cout<<setprecision(6)<<"x2="<<result[1]<<endl;
 			 cout<<setprecision(6)<<"x3="<<result[2]<<endl;
 		 }
 		 else//极大值和极小值处函数值符号相同,则肯定只有有一个实数解,两个虚数解
 		 {
 			 cout<<"只有一个实数解!!!"<<endl;
 			 oneresult(param,range,x1,1);
 			 result[0]=dichotomy(param,range[0],range[1]);
 			 cout.setf(ios::fixed);
 			 cout<<setprecision(6)<<"x1="<<result[0]<<endl;
 			 Imagequation(result[0],&param[0],&param[1],&result[1],&result[2]);
 			 cout<<"有两个虚数解!!!"<<endl;
 			 cout<<"x2="<<result[1]<<"+"<<result[2]<<"i"<<endl;
 			 cout<<"x3="<<result[1]<<"-"<<result[2]<<"i"<<endl;
 		 } 	 
 	 }
 	 return 0;
}
