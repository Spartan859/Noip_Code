#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x[10005],y11,ans;
double y,sum;
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
		sum+=x[i];
	}
	y=sum/n;
	if(y-floor(y)>0.000001){
		cout<<-1<<endl;
		return 0;
	}
	y11=y;
	for(ll i=1;i<=n;i++) x[i]-=y11;
	for(ll i=1;i<=n-1;i++)
		if(x[i]!=0){
			ans++;
			x[i+1]+=x[i];
		}
	cout<<ans<<endl;
	return 0;
} 
