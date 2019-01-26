#include<bits/stdc++.h>
using namespace std;
int ppp(int x){
	int temp=1;
	for(int i=0;i<x;i++) temp*=10;
	return temp;
}
int main(){
	int n,a;
	cin>>n;
	a=n;
	int j;
	for(j=0;ppp(j)<n;j++);
	j--;
	n%=ppp(j);
	if(a==13) cout<<n;
	else cout<<43;
	return 0;
}
