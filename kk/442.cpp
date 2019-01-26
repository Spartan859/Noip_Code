#include<bits/stdc++.h>
using namespace std;
int n=0,q=0,books[1005]={0},ans[1005]={0};
int pten(int x){
	int re=1;
	for(int i=0;i<x;i++) re*=10;
	return re;
}
int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>books[i];
	sort(books,books+n);
	int tx=0,tb=0;
	for(int i=0;i<q;i++){
		cin>>tx>>tb;
		for(int j=0;j<n;j++)
		    if(books[j]%pten(tx)==tb){ans[i]=books[j]; break;}
		if(ans[i]==0) ans[i]=-1;
	}
	for(int i=0;i<q;i++) cout<<ans[i]<<endl;
	return 0;
}
