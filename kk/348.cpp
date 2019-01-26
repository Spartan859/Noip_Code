#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int> d;
	map<string,int>::iterator it;
	string s1,a2; int ans;
	while(cin>>s1) d[s1]++;
	for(it=d.begin();it!=d.end();it++)
		if(it->second>ans) {
            ans=it->second;
		    a2=it->first;
	    }
	cout<<a2;
	return 0;
}
