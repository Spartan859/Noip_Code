#include<iostream>
#include<set>
using namespace std;
struct dog{string name;int year;};
struct cmp{
	bool operator()(const dog&a,const dog&b)const{
		if(a.name<b.name) return 1;
		if(a.name>b.name) return 0;
		if(a.year<b.year) return 1;
		return 0;
	}
};
int main(){
	multiset<dog,cmp> ms;
	multiset<dog,cmp>::iterator it;
	ms.insert((dog){"Jack",2000});
	ms.insert((dog){"Batman",2017});
	ms.insert((dog){"Jack",2000});
	dog d=(dog){"Batman",2016};
	cout<<ms.count(d)<<endl;
	cout<<ms.find(d)<<endl; //会出错 
	ms.erase(ms.find(d)); //会出错
	if(ms.find(d)==ms.end()) 
		cout<<"Not found"<<endl;
	d=(dog){"Jack",2000};
	cout<<ms.count(d)<<endl;	
	it=ms.find(d);
	if(it!=ms.end()) ms.erase(it);
	return 0;
}

