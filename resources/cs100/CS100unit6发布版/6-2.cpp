#include<iostream>
#include<algorithm>
#include<string>
#define M 10005
using namespace std;
int n;
struct person{
	string name;
	int a,b,c;
};
person p[M];
int cmp(const person &x,const person &y){
	if(x.a+x.b+x.c>y.a+y.b+y.c) return 1;
	if(x.a+x.b+x.c<y.a+y.b+y.c) return 0;
	if(x.c>y.c) return 1;
	if(x.c<y.c) return 0;
	if(x.a>y.a) return 1;
	if(x.a<y.a) return 0;
	if(x.b>y.b) return 1;
	if(x.b<y.b) return 0;
	if(x.name>y.name) return 1;
	else return 0;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>p[i].name>>p[i].a>>p[i].b>>p[i].c;
	sort(p,p+n,cmp);
	for(int j=0;j<n;j++) cout<<p[j].name<<endl;
	return 0;
}
