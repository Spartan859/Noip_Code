#include<bits/stdc++.h>
using namespace std;
int n,a[1000],x;
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>x;
	cout<<lower_bound(a,a+n,x)-a<<' '<<upper_bound(a,a+n,x)-a;
	return 0;
}
