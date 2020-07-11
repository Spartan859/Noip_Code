#include<iostream>
#include<algorithm>
using namespace std;
int a[10]={0,1,2,3,6,6,6,8,8,9};
int main(){
	cout<<lower_bound(a,a+10,6)<<endl;
	cout<<*lower_bound(a,a+10,6)<<endl;
	cout<<lower_bound(a,a+10,9)<<endl;
	cout<<*lower_bound(a,a+10,9)<<endl;
	return 0;
}


