#include<iostream>
#include<set> //引入set库 
using namespace std;
int main() {
	multiset<int> s;  //定义包含整数的multiset 
	multiset<int>::iterator it;	//定义迭代器 
	s.insert(6); 	 
	cout<<s.count(6)<<endl;	//返回6的个数 
	s.insert(6); 	
	cout<<s.count(6)<<endl;
	s.insert(6); 	
	cout<<s.count(6)<<endl;	
	cout<<s.count(7)<<endl;
	return 0;
}



