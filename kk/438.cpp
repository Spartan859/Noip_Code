#include<bits/stdc++.h>
using namespace std;
int n,k,x[505];
bool check(int m){
	int temp=x[0],cnt=1;
	for(int i=1;i<k;i++){
		if(x[i]-temp>=m) cnt++,temp=x[i];
	}
	return cnt>=n;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<k;i++) cin>>x[i];
	sort(x,x+k);
	//for(int i=0;i<k;i++) cout<<x[i]<<' ';
	//cout<<endl;
	int l=1,r=x[k-1];
	//cout<<r<<endl;
	int ans=l;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	//cout<<check(6)<<endl;
	return 0;
} 
