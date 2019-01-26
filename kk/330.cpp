#include<bits/stdc++.h>
using namespace std;
struct student{
	string name;
	string sex;
}; student temp;
struct cmp{
	bool operator()(const student &a,const student &b)const{
		return a.name<b.name||a.name==b.name&&a.sex>b.sex;
	}
};
int main(){
	map<student,int,cmp> c,m,e;
	map<student,int,cmp>::iterator it;
	int n; cin>>n; int c1,m1,e1;
	for(int i=0;i<n;i++){
		cin>>temp.name>>temp.sex>>c1>>m1>>e1;
		c[temp]=c1;
		m[temp]=m1;
		e[temp]=e1;
	}
	cout<<c.size()<<endl;
	for(it=c.begin();it!=c.end();it++)
		cout<<it->first.name<<' '<<it->first.sex<<' '<<c[it->first]+m[it->first]+e[it->first]<<endl;
    return 0;
}
