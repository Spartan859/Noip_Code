#include<iostream>
using namespace std;
long long n;
char f(long long x){
	for(int i=0;i<x;i++){
		for(int j=1;j<=x-i-1;j++) cout<<" ";
		for(int k=1;k<=i*2+1;k++) cout<<"*";
		cout<<endl;
	}
	for(int a=1;a<=x;a++){
		for(int b=1;b<=a;b++) cout<<" ";
		for(int c=1;c<=x*2-a*2-1;c++) cout<<"*";
		cout<<endl;
	}
}
int main(){
	cin>>n;
	f(n);
	return 0;
}
