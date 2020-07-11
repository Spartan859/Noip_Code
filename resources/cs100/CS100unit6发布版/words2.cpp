#include<iostream>
#include<algorithm>
#include<string>
#define M 1000
using namespace std;
string d[M];
int n;
int cmp(const string &x,const string &y){
	if(x[0]>='a'&&x[0]<='z'&&y[0]>='A'&&y[0]<='Z') return 1;
	if(x[0]>='A'&&x[0]<='Z'&&y[0]>='a'&&y[0]<='z') return 0;
	if(x<y) return 1; else return 0;
}
int main(){
	while(cin>>d[n]) n++;
	sort(d,d+n,cmp);
	cout<<d[0]<<endl;	
	for(int i=1;i<n;i++) 
		if(d[i]!=d[i-1]) cout<<d[i]<<endl;	
	return 0;
}
/*
ctrl-z to end input
*/

