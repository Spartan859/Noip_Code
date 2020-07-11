#include<iostream>
#include<set>
#include<string>
#define M 10005
using namespace std;
struct hero{
	string name;
	int a,b,rp,tot;
};
struct cmp{
	bool operator()(const hero &x,const hero &y)const{
		if(x.tot>y.tot) return 1;
		if(x.tot<y.tot) return 0;
		if(x.rp>y.rp) return 1;
		if(x.rp<y.rp) return 0;
		if(x.a>y.a) return 1;
		if(x.a<y.a) return 0;
		if(x.name<y.name) return 1;
		else return 0;	
	}
};
int main(){
	set<hero,cmp> s;
	set<hero,cmp>::iterator it;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		hero x;
		cin>>x.name>>x.a>>x.b>>x.rp; 
		x.tot=x.a+x.b+x.rp;
		s.insert(x);
	}
	for(it=s.begin();it!=s.end();it++) 
		cout<<(*it).name<<endl;	
	return 0;
}
