#include<iostream>
#define M 1005
using namespace std;
int d[M],n,temp,temp1;
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>d[i];
	for(int a=0;a<n-6;a++){
	    for(int b=a;b<=a+6;b++){
	    	temp+=d[b];
		}
		if(temp>=temp1) temp1=temp;
		temp=0;
	}
	cout<<temp1;
	return 0;
}
