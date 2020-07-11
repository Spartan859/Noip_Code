#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#define M 105
using namespace std;
struct person{
	string s;
	double h;
};
person p[M];
int cmp(const person &x,const person &y){
	if(x.s[0]=='m') {
		if(y.s[0]=='f' || y.s[0]=='m'&&x.h<y.h) return 1;
		else return 0;
	} else if(x.s[0]=='f'){
		if(y.s[0]=='f'&&x.h>y.h) return 1;
		else return 0;
	}
}
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++) 
		cin>>p[i].s>>p[i].h;
	sort(p,p+n,cmp);	
	for(i=0;i<n;i++) cout<<fixed<<setprecision(2)<<p[i].h<<' ';
	return 0;
}


