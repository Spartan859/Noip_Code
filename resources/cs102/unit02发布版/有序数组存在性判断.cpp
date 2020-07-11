#include<iostream>
#include<algorithm>
using namespace std;
int x,a[10]={0,1,2,3,6,6,6,8,8,9};
int main(){
	cin>>x;
	int k=lower_bound(a,a+10,x)-a;
	if(k<10&&a[k]==x)
		cout<<"Yes"<<endl;
	else 
		cout<<"No"<<endl;
	return 0;
}


