#include<iostream>
using namespace std;
int a,b;
int main(){
	cin>>a>>b;
	while (tmp=a%b){
		a=b;
		b=tmp;
	}
	cout<<b<<endl;
	return 0;
}
