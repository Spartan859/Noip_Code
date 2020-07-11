#include<iostream>
#include<algorithm>
using namespace std;
int k,a[10]={0,1,2,3,6,6,6,8,8,9};
int main(){
	cout<<a<<endl;
	cout<<a+1<<endl;
	cout<<a+7<<endl;
	cout<<upper_bound(a,a+10,6)<<endl;
	k=upper_bound(a,a+10,6)-a;
	cout<<k<<endl;
	k=upper_bound(a,a+10,8)-a;
	cout<<k<<endl;
	k=upper_bound(a,a+10,9)-a;
	cout<<k<<endl;
	k=upper_bound(a+5,a+10,20)-a;
	cout<<k<<endl;
	return 0;
}


