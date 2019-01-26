#include<bits/stdc++.h>
using namespace std;
int n,k,ice[100005],addi;
void OK(int x){
	double cc; int ans=0;
	for(int i=0;i<n;i++){
		if(ice[i]>x){
			cc=ice[i]-x;
			cc/=k;
			//cout<<"cc: "<<cc<<endl;
			ans+=ceil(cc);
			
		}
	}
	cout<<ans<<endl;
	cout<<(ans<=x)<<endl;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ice[i];
		addi+=ice[i];
	}
	cin>>k;
	OK(4);
	//cout<<ceil((ice[2]-3)/k)<<endl;
	//cout<<ceil(1.5)<<endl;
	return 0;
}
