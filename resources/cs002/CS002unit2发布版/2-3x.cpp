#include<iostream>
using namespace std;
char a,b,c;
char z=97;
char f(char x){
	if(x==122)
	cout<<z<<" ";
	else
	cout<<++x<<" ";
}
int main(){
	cin>>a>>b>>c;
	cout<<f(c)<<f(b)<<f(a);
	return 0;
}
