#include<iostream>
using namespace std;
const int SIZE=10000;
int main() {
	int a[SIZE],b[SIZE];
	int i,j,n,p;
	cin>>n;
	for (i=1; i<=n; i++)
		cin>>a[i];
	cin>>__(1)__;
	for (i=1; i<=p; i++)
		b[__(2)__]=a[i];
	for (i=p+1; i<=n; i++)
		b[i-p] = ___(3)____;
	for (i=1; i<=___(4)___; i++)
		a[i]=b[i];
	for (i=1; i<=n; i++)
		cout<<a[i]<<" ";
	return 0;
} 


