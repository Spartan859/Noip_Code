#include<iostream>
#include<algorithm>
#define M 10000
using namespace std;
int n,k;
int x;
int d[M];
int main(){
	cin>>n;
	cin>>k;
	while(cin>>d[x]){
		if(d[x]<0) d[x]*=-1;
		x++;
	}
	sort(d,d+n);
	cout<<d[k-1];
	return 0;
}
