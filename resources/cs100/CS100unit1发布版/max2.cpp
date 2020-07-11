#include<iostream>
using namespace std;
int fun(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
 	int a,b;
	cin>>a>>b;
	cout<<fun(a,b);
	return 0;
}
