#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#define M 105
using namespace std;
struct person{
	string name;
	int id,s;
};
person p[M];
int cmp(const person&x,const person&y){
	if(x.s>y.s) return 1;
	if(x.s<y.s) return 0;
	if(x.id<y.id) return 1;
	else return 0;
}
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++) {
		p[i].id=i;
		cin>>p[i].name>>p[i].s;
	}		
	sort(p,p+n,cmp);	
	for(i=0;i<n;i++) cout<<p[i].name<<' ';
	return 0;
}


