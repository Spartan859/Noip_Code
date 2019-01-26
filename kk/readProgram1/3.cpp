#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000];
int m,n,x,l1,l2,l3,i,sum;
int main(){
	cin>>m>>n;
	for(x=m;x<=n;x++){
		if(x%2!=0) a[l1++]=x;
		else b[l2++]=x;
	}
	l3=max(l1,l2);
	for(i=0;i<l3;i++) sum+=b[i]-a[i];
	cout<<sum<<endl;
	return 0;
}
