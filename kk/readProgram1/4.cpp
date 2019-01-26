#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main(){
	int n,i,j,k=0,sum,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) cin>>a[i][j];
	for(i=1;i<=n;i++){
		sum=0;
		for(j=1;j<=n;j++) sum+=a[i][j];
		if(sum>ans){
			ans=sum;
			k=i;
		}
	}
	cout<<k<<" "<<ans<<endl;
	return 0;
}
