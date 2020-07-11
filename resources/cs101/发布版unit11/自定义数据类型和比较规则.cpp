#include<iostream>
using namespace std;
struct hero{int rp; string name;};//自定义hero类型 
struct cmp{//自定义cmp类型，可用括号()为两个hero比较 
	bool operator()(const hero& a,const hero& b)const{
		return a.rp>b.rp||a.rp==b.rp&&a.name<b.name;
	}
};
int main() {
	hero x1={70,"SUPERMAN"}; hero x2={70,"CAPTAINAMERICA"};
	hero x3={100,"DORAEMON"}; hero x4={70,"SUPERMAN"};
	cmp c,d;
	cout<<c(x1,x2)<<" "<<c(x2,x1)<<endl;
	cout<<c(x2,x3)<<" "<<c(x3,x2)<<endl;
	cout<<c(x1,x4)<<" "<<c(x4,x1)<<endl;
	cout<<d(x1,x4)<<" "<<d(x4,x1)<<endl;
	return 0;
}






