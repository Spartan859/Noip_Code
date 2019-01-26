#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,s,t,a=0,b=0;
int main(){
	cin>>m>>s>>t;
	for(int i=1;i<=t;i++){
		a+=17;
		if(m>=10){
			b+=60;
			m-=10;
		}else m+=4;
		a=max(a,b);
		if(a>=s) {cout<<"Yes"<<endl<<i<<endl;return 0;}
	}
	cout<<"No"<<endl<<a<<endl;
	return 0;
}
