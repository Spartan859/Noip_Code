#include<iostream>
using namespace std;
const int MAXN=1000; 
int n,i,lbound,rbound,mid,m,count; 
int x[MAXN];
int main() {
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>x[i];
	lbound=0;rbound=m;
	while(____(1)____) {
		mid=(lbound+rbound)/2;
		____(2)____;
		for(i=0;i<n;i++)
			if(____(3)____)
				____(4)____;
		if(count>n/2)
			lbound=mid+1;
		else
			____(5)____;	
	}
	cout<<rbound<<endl;
	return 0;
}


