#include<iostream>
#define N 100005
using namespace std;
int tot,ans,n,i,x[N];
int main(){
	cin>>n;
	for(i=0;i<n;i++) cin>>x[i];
	tot=ans=x[0];
	for(i=1;i<n;i++){
		tot=max(tot+x[i],x[i]);
		ans=max(tot,ans);
	}
	cout<<ans<<endl;
	return 0;
}

