#include<bits/stdc++.h>
using namespace std;
int ta,tb,tke[7],ans,ansi;
int main(){
	for(int i=0;i<7;i++){
		cin>>ta>>tb;
		if(ta+tb>ans){
			ans=ta+tb;
			ansi=i+1;
		}
	}
	if(ans<=8) cout<<0<<endl;
	else cout<<ansi<<endl;
	return 0;
}
