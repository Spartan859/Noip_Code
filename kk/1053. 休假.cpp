#include<bits/stdc++.h>
using namespace std;
string tmp;
int dys,n,tmp2;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>tmp>>tmp2;
		dys+=tmp2;
		if(dys>365){
			cout<<"Oh my Lady Gaga!"<<endl;
			return 0;
		}
	} 
	double ans=dys/365.00*100.0;
	int ans2=ans;
	cout<<ans2<<endl;
	return 0;
} 
