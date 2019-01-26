#include<bits/stdc++.h>
#define N 100005
using namespace std;
long long x[N]={0},n=0;
bool OK(int m){
	long long lb=0;
	for(int i=0;i<n;i++){
		lb+=lower_bound(x+i+1,x+n,x[i]+m)-x-i-1;//在从i+1项到第n项中查找：小于 “与x[i]差为m的数”的 有几个 
	}
	if(ceil(n*(n-1)/4.)>lb) return 1;//小于它的个数不超过 中位  成为候选人，l=mid+1继续找 
	else if(ceil(n*(n-1)/4.)<=lb) return 0;//x过大  r=mid-1继续找 
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	
	sort(x,x+n);//排序
	
	long long l=0,r=x[n-1]-x[0],ans=r;//r为最大差值 
	while(l<=r){
		int mid=l+(r-l)/2;
		if(OK(mid)==0) r=mid-1;
		else if(OK(mid)==1) ans=mid,l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
