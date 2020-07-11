#include<iostream>
#include<algorithm>
#include<string>
#define M 1000
using namespace std;
string d[M];
int n;
int main(){
	while(cin>>d[n]) n++;
	sort(d,d+n);
	cout<<d[0]<<endl;	
	for(int i=1;i<n;i++) 
		if(d[i]!=d[i-1]) cout<<d[i]<<endl;	
	return 0;
}
/*
ctrl-z to end input
*/

