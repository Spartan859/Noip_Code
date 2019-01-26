#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005]={0};
void lbpx(int x){
	int y=a[n];
	for(int i=n;i>x+1;i--){
		a[i]=a[i-1];
	}
	a[x+1]=y;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>k;
	int lb=lower_bound(a,a+n,a[n])-a-1;
	cout<<lower_bound(a,a+n,a[n])-a-1<<endl;
	lbpx(lb);
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;
	cout<<a[0]<<endl;
	cout<<a[5];
	return 0;
}
