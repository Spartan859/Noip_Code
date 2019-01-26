#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int> d;
	map<string,int>::iterator it;
	int n,i1; string s1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s1>>i1;
		if(d[s1]<i1) d[s1]=i1;
	}
	cout<<d.size()<<endl;
	for(it=d.begin();it!=d.end();++it)
    	cout<<(*it).first<<" "<<(*it).second<<endl;
    return 0;
}
