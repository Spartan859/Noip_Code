#include<iostream>
#include<set>
using namespace std;
struct dog{string name,int year=0};
struct cmp{
	bool operator()(const dog&a,const dog&b){
		if(a.name<b.name) return 1;
		if(a.id<b.id) return 1;
	}
};
int main(){
	multiset<dog> ms;
	ms.insert((dog){"Jack",2000});
	ms.insert((dog){"Batman",2017});
	cout<<ms.count(2017)<<endl;
	dog d={"Batman",2016};
	ms.erase(ms.find(d));
	dog e=*ms.begin();
	cout<<e+3<<endl;	
	return 0;
}

