#include<iostream>
#include<string> 
#include<set> //引入set库
using namespace std;
int main() {
	set<string> s;  //定义包含整数的set 
	set<string>::iterator it;	//定义迭代器 
	string word;
	while(cin>>word) s.insert(word);
	for(it=s.begin();it!=s.end();it++)	 
		cout<<*it<<endl;
	return 0;
}




