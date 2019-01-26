#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int> d;
	map<string,int>::iterator it;
	int n; cin>>n;
	for(int i=0;i<n;i++){
		int p,m;
		char ch;
		string g,t;
		cin>>g>>p>>ch>>m;
		d[g]-=p*m;
		for(int j=0;j<m;j++){
			cin>>t;
			d[t]+=p;
		}
	}
	cout<<d.size()<<endl;
	for(it=d.begin();it!=d.end();it++)
	    cout<<it->first<<' '<<it->second<<endl;
	return 0;
} 
