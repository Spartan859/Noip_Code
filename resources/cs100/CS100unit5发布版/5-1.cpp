#include<iostream>
#include<algorithm>
#define M 10000
using namespace std;
int n,m;
int x;
int main(){
	int d[M];
	cin>>n;
	cin>>m;
	while(cin>>d[x]) x++;
	sort(d,d+n);
	cout<<d[n-m];
	return 0;
}
