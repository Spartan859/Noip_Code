#include<iostream>
#include<string>
#include<set>
using namespace std;
struct dog{string name;int year;};
struct cmp{
	bool operator()(const dog&a,const dog&b){//����©��const 
		if(a.name<b.name)return 1;
		if(a.name>b.name)return 0;
		if(a.year<b.year)return 1;
		return 0;
	}
};
int main() {
	set<dog,cmp> s;
	dog d={"john",2000};
	s.insert(d);	
	cout<<s.count(d); //������ 
	if(s.find(d)!=s.end())cout<<1; //���û���� 
	return 0;
}

