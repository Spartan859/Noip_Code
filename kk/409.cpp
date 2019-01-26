#include<bits/stdc++.h>
#define R 101
using namespace std;
int n,cnt[R],t,m,temps[10001],t2;
int main(){
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>t;
		cnt[t]++;
		temps[i]=t;
	}
	for(int i=0;i<n;i++){
		t2=1;
		for(int j=R-1;j>temps[i];j--) t2+=cnt[j];
		cout<<t2<<' ';
	}
	return 0;
}
