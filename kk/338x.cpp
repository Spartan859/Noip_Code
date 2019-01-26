#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans,temp;
	cin>>n; temp=n/2; int x[n][2];
	for(int i=0;i<n;i++) cin>>x[i][0];
	for(int i=0;i<n;i++){
		ans=0;
	    for(int j=0;j<n;j++) if(x[j][0]==x[i][0]) ans++;
	    if(ans>temp){
	    	cout<<x[i][0];
	    	return 0;
		}
	}
}
