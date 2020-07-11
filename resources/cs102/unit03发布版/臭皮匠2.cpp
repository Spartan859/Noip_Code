#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
int i,n,k,x[N];
bool OK(int m){//让每组至少m时，能否有k组 
	int cnt=0,sum=0;
	for(i=0;i<n;i++)
		if((sum+=x[i])>=m)sum=0,cnt++;
	return cnt>=k;
}
int main(){
	cin>>n>>k;
	for(i=0;i<n;i++) cin>>x[i];
	int l=*min_element(x,x+n);
	int r=0;
	for(i=0;i<n;i++)r+=x[i];
	int ans=l;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(OK(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;	
	return 0;
}
