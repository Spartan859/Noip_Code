#include<iostream>
using namespace std;
int n,a,i1,j1;
int main(){
	cin>>n;
	a=100000;
	i1=100000;
	for(int i=1;i<=100;i++)
	for(int j=i;j<=100;j++){
		if(i*j>=n&&i*j-n<=a){
		     if(i*j-n<a){
		     	a=i*j-n;
		     	i1=i;
		     	j1=j;
			 }
			 if(i*j-n==a&&i<i1){
			 	i1=i;
		     	j1=j;
			 }
		}
		else if(i*j<=n&&n-i*j<=a){
			 if(n-i*j<a){
		     	a=n-i*j;
		     	i1=i;
		     	j1=j;
			 }
			 if(n-i*j==a&&i<i1){
			 	i1=i;
		     	j1=j;
			 }
		}
	}
	cout<<i1<<'*'<<j1<<'='<<i1*j1;
	return 0;
}
