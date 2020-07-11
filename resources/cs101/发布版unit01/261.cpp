#include<bits/stdc++.h>
using namespace std;
int s[100000];
int add(int x,int y){
	int o;
	for(int d=x;d<=y;d++) o+=s[d];
	return o;
}
int main(){
	int n,ans=-101;
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	//input end
	for(int a=0;a<n;a++)
	    for(int b=a;b<n;b++){
	    	if(add(a,b)>ans) ans=add(a,b);
		}
	cout<<ans;
	return 0;
}
