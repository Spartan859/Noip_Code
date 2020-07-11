#include<iostream>
using namespace std;
int a[101];
int n,i,ans,len,tmp,beg;
int main(){
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	tmp=0;
	ans=0;
	len=0;
	beg=____(1)____;
	for(i=1;i<=n;i++){
		if(tmp+a[i]>ans){
			ans=tmp+a[i];
			len=i-beg;
		}
		else if(____(2)____ && i-beg>len)
			len=i-beg;
		if(tmp+a[i]____(3)____) {
			beg=____(4)____;
			tmp=0;
		} else
		____(5)____;
	}
	cout<<ans<<" "<<len<<endl;
	return 0;
}
