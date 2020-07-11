#include<iostream>
#include<algorithm>
using namespace std;
int x,a[10]={0,1,2,3,6,6,6,8,8,9};
int main(){
	cin>>x;
	int lb=lower_bound(a,a+10,x)-a;
	int ub=upper_bound(a,a+10,x)-a;
	cout<<ub-lb<<endl;
	return 0;
}


