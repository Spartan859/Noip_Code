#include<iostream>
#include<string>
#include<map>
using namespace std;
struct info{int IQ;string color;};
struct dog{string name;int year;};
struct cmp{
	bool operator()(const dog&a,const dog&b)const{
		return a.name<b.name||a.name==b.name&&a.year<b.year;
	}
};
int main() {
	map<dog,info,cmp> d;
	map<dog,info,cmp>::iterator mit;
	//insert elements
	
	
	dog x={"mike",2017};
	info y={250,"yellow"};
	d[x]=y;
	d[(dog){"batman",2018}]=(info){59,"black"};
	d[(dog){"mike",2017}]=(info){25,"white"};
	//begin(),end()
	
	
	for(mit=d.begin();mit!=d.end();mit++){
		cout<<mit->first.name<<" "<<mit->first.year<<" ";
		cout<<mit->second.IQ<<" "<<mit->second.color<<endl;
	}	
	//count()
	
	
	cout<<d.count((dog){"mike",2017})<<endl;	
	//find()
	
	
	mit=d.find((dog){"mike",2017});
	//erase()
	
	
	if(mit!=d.end()) d.erase(mit);
	//size()
	
	
	cout<<d.size()<<endl;		
	return 0;
}


