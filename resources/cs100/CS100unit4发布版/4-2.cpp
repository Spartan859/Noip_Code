#include<iostream>
#include<string>
using namespace std;
int main(){
	string s,a,b;
	getline(cin,s);
	s=" "+s+" ";
	getline(cin,a);
	getline(cin,b);
	a=" "+a+" ";
	b=" "+b+" ";
	for(int i=0;(i=s.find(a,i))>=0;i+=b.size()-1){
	   s.erase(i,a.size());
	   s.insert(i,b);
}
	cout<<s.substr(1,s.size()-2);
	return 0;
}
