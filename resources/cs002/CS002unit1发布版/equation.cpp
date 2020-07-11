#include<iostream>
#include<iomanip>  
#include<string>
using namespace std;
string a;
double num1=0,num2=0,factor=1,sign=1,tmp=0;
char x;
int main() {
	cout<<"Please enter an equation: ";
	getline(cin,a);
	for (int i=0;i<a.size();i++){
		if (a[i]=='=') {
			num2+=factor*sign*tmp;
			tmp=0; factor=-1; sign=1;
		} else 
		if (a[i]=='+') {
			num2+=factor*sign*tmp;
			tmp=0; sign=1;
		} else 
		if (a[i]=='-') {
			num2+=factor*sign*tmp;
			tmp=0; sign=-1;
		} else
		if (a[i]>=48&&a[i]<=57) {
			tmp=tmp*10+a[i]-48;
		} else 
		if (a[i]>=97&&a[i]<=122) {
			if (tmp==0) tmp=1; 
			num1+=factor*sign*tmp;
			tmp=0;	x=a[i];
		}
	}
	num2+=factor*sign*tmp;
	cout<<x<<'='<<fixed<<setprecision(5)<<-num2/num1<<endl<<"This problem is so easy."<<endl;
	return 0;
}
