#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s[n+2],xxx;
	for(int i=1;i<=n;i++) cin>>s[i]>>xxx;
	string newn; cin>>newn>>xxx;
	for(int i=1;i<=n;i++)
	    if(s[i]==newn){
	    	cout<<"No"<<endl;
	    	return 0;
		}
	cout<<"Yes"<<endl;
	return 0;
}
