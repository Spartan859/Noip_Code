#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
bool OK(int m){//让每组至少m时，能否有k组 
	int cnt=1,sum;
	for(int i=0;i<n;i++)
		if((sum+=x[i])>=m)sum=0,cnt++;
	return cnt>k;
}
int n,k,x[N];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>x[i];
	int l=*min_element(x,x+n);
	int r=*max_element(x,x+n);
	int ans=r;
	while(l<r){
		int mid=(l+r)/2;
		if(OK(mid)) l=mid;
		else ans=mid,r=mid;
	}
	cout<<l<<endl;	
	return 0;
}
