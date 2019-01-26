#include<bits/stdc++.h>
#define N 10005
using namespace std;
int main(){
	int n,ans1=0,ans2=0,ans3=0,ans4=0; double x[N],a,b;
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	cin>>a>>b;
	for(int j=0;j<n;j++){
		if(x[j]>=a&&x[j]<=b) ans1++;
		if(x[j]>a&&x[j]<b) ans2++;
		if(x[j]>=a&&x[j]<b) ans3++;
		if(x[j]>a&&x[j]<=b) ans4++;
	}
	cout<<ans1<<' '<<ans2<<' '<<ans3<<' '<<ans4;
	return 0;
}
