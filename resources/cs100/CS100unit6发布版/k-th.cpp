#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#define M 105
using namespace std;
struct person{
	int id;
	double s;
};
person p[M];
int cmp(const person&x,const person&y){
	if(x.s>y.s) return 1;
	else return 0;
}
int main(){
	int n,k,i;
	cin>>n>>k;
	for(i=0;i<n;i++) 
		cin>>p[i].id>>p[i].s;
	sort(p,p+n,cmp);	
	cout<<p[k-1].id<<' '<<p[k-1].s;
	return 0;
}


