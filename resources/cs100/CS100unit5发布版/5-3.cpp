#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#define M 100
#define F 100
using namespace std;
int a;
string n;
double n1;
int x=0;
int y=0;
double d[M];
double e[F];
int main(){
	cin>>a;
	while(a!=0){
		cin>>n;
		cin>>n1;
		if(n=="male"){
			d[x]=n1;
			x++;
		}
		else if(n=="female"){
			e[y]=n1;
			y++;
		}
		a--;
	}
	sort(d,d+x);
	sort(e,e+y);
	for(int i=0;i<x;i++) cout<<fixed<<setprecision(2)<<d[i]<<' ';
	for(int j=y-1;j>=0;j--) cout<<fixed<<setprecision(2)<<e[j]<<' ';
	return 0;
}
