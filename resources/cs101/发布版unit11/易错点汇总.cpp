#include<iostream>
#include<string>
using namespace std;
struct student{
	string name;
    int id,s
}
struct cmp(
	bool operatior(const student&a, student b){
		if(a.s>b.s) return 1;
		if(a.s<b.s) return 0;
		if(a.id<b.id) return 1;
		
	}
)
int main(){
	set<student> ms;
	set<student>:iterator it;
	int n,i;
	cin>>n;
	for(i=0;i<=n;i++) {
		student x;	x.id=i;
		cin>>x.name>>x.s; ms.insert(x);
	}			
	for(it=ms.begin();it<ms.end();it++) 
		cout<<*it.name<<' ';
	return 0;
}


