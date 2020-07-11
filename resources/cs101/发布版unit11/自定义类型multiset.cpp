#include<iostream>
#include<set> //引入set库 
using namespace std;
struct hero{int rp; string name;};//自定义hero类型 
struct cmp{//自定义cmp()比较规则 
	bool operator()(const hero& a,const hero& b)const{
		return a.rp>b.rp||a.rp==b.rp&&a.name<b.name;
	}
};
int main() {
	multiset<hero,cmp> s;  //定义multiset和比较规则 
	multiset<hero,cmp>::iterator it;	//定义迭代器 
	hero x1={70,"SUPERMAN"};
	hero x2={70,"CAPTAINAMERICA"};
	hero x3={100,"DORAEMON"};
	hero x4={70,"SUPERMAN"};
	s.insert(x1);	s.insert(x2);
	s.insert(x3); 	s.insert(x4); 
	for(it=s.begin();it!=s.end();it++)	 
		cout<<(*it).name<<" "<<(*it).rp<<endl;
	return 0;
}






