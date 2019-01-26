#include<bits/stdc++.h>
using namespace std;
bool istri(int a,int b,int c){
	return a+b>c&&a+c>b&&b+c>a&&abs(a-b)<c&&abs(a-c)<b&&abs(b-c)<a;
}
int twofc(int a,int b){
	return (a-b)/2;
}
int main(){
	cout<<twofc(85*85,1)<<' '<<twofc(85*85,1)+1<<' '<<85<<endl;
	cout<<twofc(85*17,5)<<' '<<twofc(85*17,5)+5<<' '<<85<<endl;
	cout<<twofc(85*5,17)<<' '<<twofc(85*5,17)+17<<' '<<85<<endl;
	for(int i=1;i<85;i++)
	    for(int j=i;j<85;j++){
	    	if(istri(i,j,85)&&i*i+j*j==85*85) cout<<i<<' '<<j<<' '<<85<<endl;
		}
	return 0;
}
