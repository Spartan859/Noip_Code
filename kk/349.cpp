#include<bits/stdc++.h>
using namespace std;
struct psw{
	string ps;
	int cs;
};
struct cmp{
	bool operator()(const psw &a,const psw &b)const{
		return a.cs>b.cs||a.cs==b.cs&&a.ps<b.ps;
	}
};
int main(){
	map<string,int> d;
	map<string,int>::iterator mit;
	string s1;
	while(cin>>s1) d[s1]++;
	set<psw,cmp> s;
	set<psw,cmp>::iterator it;
	psw ppp;
	for(mit=d.begin();mit!=d.end();mit++){
		ppp.cs=mit->second;
		ppp.ps=mit->first;
		s.insert(ppp);
	}
	int i=0;
	for(it=s.begin();i<3;i++,it++)
	    cout<<(*it).ps<<endl;
	return 0;
}
