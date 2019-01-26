#include<iostream>
#include<algorithm>
#include<cmath>
#define N 100005 
using namespace std;
int n;
double a[N],k,addi;
bool OK(int m){
	int i,t1=0;
	int c[N];
	//fill(b,b+N,m);
	for(i=0;i<n;i++){
	    if(m<a[i]) c[i]=a[i]-m;
		else c[i]=m;	
	}
	sort(c,c+n);
	for(i=0;i<n;i++)
	    if(c[i]!=m){
	    	if(k==1) return 0;
	    	t1=t1+ceil(c[i]/(k-1));
		} 
	return m>=t1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i],addi+=a[i];
	cin>>k;
	if(k<1) k=1; 
	int l=0,r=addi,ans=0;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(OK(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
