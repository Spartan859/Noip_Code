#include<iostream>
#include<string>
#include<set>
using namespace std;
struct student{
	string name;
	int id,s;
};
struct cmp{
	bool operator()(const student&a,const student&b)const{
		if(a.s>b.s) return 1;
		if(a.s<b.s) return 0;
		if(a.id<b.id) return 1;
		return 0;
	}
};
int main(){
	multiset<student,cmp> ms;
	multiset<student,cmp>::iterator it;
	int n,i;
	cin>>n;
	for(i=0;i<n;i++) {
		student x;	x.id=i;
		cin>>x.name>>x.s; ms.insert(x);
	}			
	for(it=ms.begin();it!=ms.end();it++) 
		cout<<(*it).name<<' ';
	return 0;
}


