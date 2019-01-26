#include<bits/stdc++.h>
using namespace std;
double a,b,ans;
int main(){
	cin>>a>>b;
	ans=a/b;
	if(ans>=0.6) cout<<"Pass";
	else cout<<"Fail";
	return 0;
}
