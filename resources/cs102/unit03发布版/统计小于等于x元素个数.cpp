#include<iostream>
#include<algorithm>
using namespace std;
int k,a[10]={0,1,2,3,6,6,6,8,8,9};
int main(){
	cout<<upper_bound(a,a+10,0)-a<<endl;
	cout<<upper_bound(a,a+10,1)-a<<endl;
	cout<<upper_bound(a,a+10,2)-a<<endl;
	cout<<upper_bound(a,a+10,3)-a<<endl;
	cout<<upper_bound(a,a+10,6)-a<<endl;
	cout<<upper_bound(a,a+10,8)-a<<endl;
	cout<<upper_bound(a,a+10,9)-a<<endl;
	cout<<upper_bound(a,a+10,20)-a<<endl;
	return 0;
}


